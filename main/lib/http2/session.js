/**
 * @typedef {import('http2').Http2Stream} Http2Stream
 */
import { ParserBase } from './parserbase.js'

export class Http2WebTransportSession {
  /**
   * @param {Object} obj
   * @param {Http2Stream} [obj.stream]
   * @param {WebSocket} [obj.ws]
   * @param {boolean} obj.isclient
   * @param {import('../types.js').CreateParserFunction} obj.createParser
   */
  constructor({ stream, ws, isclient, createParser }) {
    // @ts-ignore
    this.jsobj = undefined // the creator will set this
    if (stream) {
      this.stream = stream
    } else if (ws) {
      this.ws = ws
    } else throw new Error('Neither stream or websocket supplied')
    this.capsParser = createParser(this)
    this.unidiId = 0
    this.bidiId = 0
    this.isclient = isclient
    if (stream) {
      if (isclient) {
        stream.on('response', (headers) => {
          process.nextTick(() => {
            if (headers[':status'] === 200) {
              // on ready
              this.jsobj.onReady({})
            } else {
              this.jsobj.onClose({
                errorcode: headers[':status'],
                error: 'Session stream errored'
              })
            }
          })
        })
      } else {
        process.nextTick(() => {
          this.jsobj.onReady({})
        })
      }
      stream.on('close', () => {
        this.jsobj.onClose({
          errorcode: 0,
          error: 'Session http/2 stream closed'
        })
      })
    }
  }

  /**
   * @param {Uint8Array} chunk
   */
  writeDatagram(chunk) {
    this.capsParser.writeCapsule({
      type: ParserBase.DATAGRAM,
      headerVints: [],
      payload: chunk
    })
    process.nextTick(() => {
      this.jsobj.onDatagramSend({})
    })
  }

  orderUnidiStream() {
    let streamid = 0x2 | (this.unidiId << 2)
    if (this.isclient) streamid = streamid | 0x1
    this.capsParser.writeCapsule({
      type: ParserBase.WT_STREAM_WOFIN,
      headerVints: [streamid],
      payload: undefined
    })
    this.capsParser.newStream(streamid)
    this.unidiId++
  }

  orderBidiStream() {
    let streamid = 0x0 | (this.bidiId << 2)
    if (this.isclient) streamid = streamid | 0x1
    this.capsParser.writeCapsule({
      type: ParserBase.WT_STREAM_WOFIN,
      headerVints: [streamid],
      payload: undefined
    })
    this.capsParser.newStream(streamid)
    this.bidiId++
  }

  orderSessionStats() {
    this.jsobj.onSessionStats({
      timestamp: 0,
      expiredOutgoing: 0n,
      lostOutgoing: 0n,
      // non Datagram
      minRtt: 0,
      smoothedRtt: 0,
      rttVariation: 0,
      estimatedSendRateBps: 0n
    })
  }

  orderDatagramStats() {
    this.jsobj.onDatagramStats({
      timestamp: 0,
      expiredOutgoing: 0n,
      lostOutgoing: 0n
    })
  }

  /*
   * @returns {void}
   */
  notifySessionDraining() {}
  /**
   * @param {{ code: number, reason: string }} arg
   */
  close({ code, reason }) {
    this.capsParser.sendClose({ code, reason })
    // what to do with the reason
    if (this.stream) {
      if (this.stream.close) this.stream.close(code)
      else if (this.stream.end) this.stream.end()
      else throw new Error('http2:session not close method')
    }
    if (this.ws) this.ws.close(code === 0 ? 1000 : 1003, reason)
  }
}