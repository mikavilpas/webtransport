// flags forgotten in quiche but present in older chromium ? Copied from various chromium version from the internet

#ifdef QUIC_FLAGT

// many defaults taken from https://github.com/washezium/washezium
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
// This file intentionally does not have header guards, it's included
// inside a macro to generate values. The following line silences a
// presubmit warning that would otherwise be triggered by this:
// no-include-guard-because-multiply-included
// NOLINT(build/header_guard)
// This file contains the list of QUIC protocol flags.
// Time period for which a given connection_id should live in the time-wait
// state.
QUIC_FLAGT(int64_t, FLAGS_quic_time_wait_list_seconds, 200)
// Currently, this number is quite conservative.  The max QPS limit for an
// individual server silo is currently set to 1000 qps, though the actual max
// that we see in the wild is closer to 450 qps.  Regardless, this means that
// the longest time-wait list we should see is 200 seconds * 1000 qps, 200000.
// Of course, there are usually many queries per QUIC connection, so we allow a
// factor of 3 leeway.
//
// Maximum number of connections on the time-wait list. A negative value implies
// no configured limit.
QUIC_FLAGT(int64_t, FLAGS_quic_time_wait_list_max_connections, 600000)
// Enables server-side support for QUIC stateless rejects.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_enable_quic_stateless_reject_support,
          true)
// If true, require handshake confirmation for QUIC connections, functionally
// disabling 0-rtt handshakes.
// TODO(rtenneti): Enable this flag after CryptoServerTest's are fixed.
/*QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_require_handshake_confirmation,
          false)*/
// If true, disable pacing in QUIC.
QUIC_FLAGT(bool, FLAGS_quic_disable_pacing_for_perf_tests, false)
// If true, enforce that QUIC CHLOs fit in one packet.
QUIC_FLAGT(bool, FLAGS_quic_enforce_single_packet_chlo, true)
// If true, QUIC will use cheap stateless rejects without creating a full
// connection.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_use_cheap_stateless_rejects,
          true)
// If true, allows packets to be buffered in anticipation of a future CHLO, and
// allow CHLO packets to be buffered until next iteration of the event loop.
QUIC_FLAGT(bool, FLAGS_quic_allow_chlo_buffering, true)
// If greater than zero, mean RTT variation is multiplied by the specified
// factor and added to the congestion window limit.
QUIC_FLAGT(double, FLAGS_quic_bbr_rtt_variation_weight, 0.0f)
// Congestion window gain for QUIC BBR during PROBE_BW phase.
QUIC_FLAGT(double, FLAGS_quic_bbr_cwnd_gain, 2.0f)
// Simplify QUIC\'s adaptive time loss detection to measure the necessary
// reordering window for every spurious retransmit.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_fix_adaptive_time_loss, false)
// If true, adjust congestion window when doing bandwidth resumption in BBR.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_fix_bbr_cwnd_in_bandwidth_resumption,
          false)
// When true, defaults to BBR congestion control instead of Cubic.
// QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_default_to_bbr, false)
// If buffered data in QUIC stream is less than this threshold, buffers all
// provided data or asks upper layer for more data.
QUIC_FLAGT(uint32_t, FLAGS_quic_buffered_data_threshold, 8192u)
// Max size of data slice in bytes for QUIC stream send buffer.
QUIC_FLAGT(uint32_t, FLAGS_quic_send_buffer_max_data_slice_size, 4096u)
// If true, QUIC supports both QUIC Crypto and TLS 1.3 for the handshake
// protocol.
QUIC_FLAGT(bool, FLAGS_quic_supports_tls_handshake, false)
// Allow QUIC to accept initial packet numbers that are random, not 1.
QUIC_FLAGT(bool, FLAGS_quic_restart_flag_quic_enable_accept_random_ipn, true)
// If true, enable QUIC v43.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_enable_version_43, true)
// Enables 3 new connection options to make PROBE_RTT more aggressive
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_bbr_less_probe_rtt, false)
// If true, enable QUIC v99.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_enable_version_99, false)
// When true, set the initial congestion control window from connection options
// in QuicSentPacketManager rather than TcpCubicSenderBytes.
// QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_unified_iw_options, false)
// Number of packets that the pacing sender allows in bursts during pacing.
QUIC_FLAGT(int32_t, FLAGS_quic_lumpy_pacing_size, 1)
// Congestion window fraction that the pacing sender allows in bursts during
// pacing.
QUIC_FLAGT(double, FLAGS_quic_lumpy_pacing_cwnd_fraction, 0.25f)
// If true, static streams in a QuicSession will be stored inside dynamic
// stream map. static_stream_map will no longer be used.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_eliminate_static_stream_map,
          false)
// Default enables QUIC ack decimation and adds a connection option to disable
// it.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_enable_ack_decimation, false)
// If true, QUIC offload pacing when using USPS as egress method.
// QUIC_FLAGT(bool, FLAGS_quic_restart_flag_quic_offload_pacing_to_usps2, false)
// Max time that QUIC can pace packets into the future in ms.
QUIC_FLAGT(int32_t, FLAGS_quic_max_pace_time_into_future_ms, 10)
// Smoothed RTT fraction that a connection can pace packets into the future.
QUIC_FLAGT(double, FLAGS_quic_pace_time_into_future_srtt_fraction, 0.125f)
// Mechanism to override version label and ALPN for IETF interop.
QUIC_FLAGT(int32_t, FLAGS_quic_ietf_draft_version, 0)
// If true, enable QUIC v44.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_enable_version_44, true)
// Stop checking QuicUnackedPacketMap::HasUnackedRetransmittableFrames and
// instead rely on the existing check that bytes_in_flight > 0
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_optimize_inflight_check, false)
// When you\'re app-limited entering recovery, stay app-limited until you exit
// recovery in QUIC BBR.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_bbr_app_limited_recovery, false)
// If true, stop resetting ideal_next_packet_send_stime_ in pacing sender.
/* QUIC_FLAGT(
    bool,
    FLAGS_quic_reloadable_flag_quic_donot_reset_ideal_next_packet_send_time,
    false)*/
// If true, enable experiment for testing PCC congestion-control.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_enable_pcc3, false)
// When true, ensure BBR allows at least one MSS to be sent in response to an
// ACK in packet conservation.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_bbr_one_mss_conservation, false)
// Add 3 connection options to decrease the pacing and CWND gain in QUIC BBR
// STARTUP.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_bbr_slower_startup3, false)
// When true, the LOSS connection option allows for 1/8 RTT of reording instead
// of the current 1/8th threshold which has been found to be too large for fast
// loss recovery.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_eighth_rtt_loss_detection,
          false)
// Enables the BBQ5 connection option, which forces saved aggregation values to
// expire when the bandwidth increases more than 25% in QUIC BBR STARTUP.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_bbr_slower_startup4, false)
// When true and the BBR9 connection option is present, BBR only considers
// bandwidth samples app-limited if they're not filling the pipe.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_bbr_flexible_app_limited, false)
// If true, calling StopReading() on a level-triggered QUIC stream sequencer
// will cause the sequencer to discard future data.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_stop_reading_when_level_triggered,
          false)
// If true, QuicSession::HasPendingCryptoData checks whether the crypto stream's
// send buffer is empty. This flag fixes a bug where the retransmission alarm
// mode is wrong for the first CHLO packet.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_fix_has_pending_crypto_data,
          true)
// When true, fix initialization and updating of
// |time_of_first_packet_sent_after_receiving_| in QuicConnection.
QUIC_FLAGT(
    bool,
    FLAGS_quic_reloadable_flag_quic_fix_time_of_first_packet_sent_after_receiving,
    true)
// When the STMP connection option is sent by the client, timestamps in the QUIC
// ACK frame are sent and processed.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_send_timestamps, false)
// If true, dispatcher passes in a single version when creating a server
// connection, such that version negotiation is not supported in connection.
QUIC_FLAGT(bool,
          FLAGS_quic_restart_flag_quic_no_server_conn_ver_negotiation2,
          false)
// If true, enable QUIC version 46.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_enable_version_46, true)
// When in STARTUP and recovery, do not add bytes_acked to QUIC BBR's CWND in
// CalculateCongestionWindow()
QUIC_FLAGT(
    bool,
    FLAGS_quic_reloadable_flag_quic_bbr_no_bytes_acked_in_startup_recovery,
    false)
// If true, use common code for checking whether a new stream ID may be
// allocated.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_use_common_stream_check, false)
// When true, remove packets from inflight where they're declared lost,
// rather than in MarkForRetransmission.  Also no longer marks handshake
// packets as no longer inflight when they're retransmitted.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_loss_removes_from_inflight,
          false)
// If true, QuicEpollClock::Now() will monotonically increase.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_monotonic_epoll_clock, false)
// If true, a client connection would be closed when a version negotiation
// packet is received. It would be the higher layer's responsibility to do the
// reconnection.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_no_client_conn_ver_negotiation,
          false)
// If true, public reset packets sent from GFE will include a kEPID tag.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_fix_spurious_ack_alarm, false)
// If true, enables the BBS4 and BBS5 connection options, which reduce BBR's
// pacing rate in STARTUP as more losses occur as a fraction of CWND.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_bbr_startup_rate_reduction,
          false)
// If true, QuicPacketCreator::SetTransmissionType will set the transmission
// type of the next successfully added frame.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_set_transmission_type_for_next_frame,
          true)
// If true, log leaf cert subject name into warning log.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_log_cert_name_for_empty_sct,
          true)
// If true, enable QUIC version 47 which adds CRYPTO frames.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_enable_version_47, false)
// If true, disable QUIC version 39.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_disable_version_39, false)
// If true, use one loss algorithm per encryption level.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_use_uber_loss_algorithm, true)
// When true, QuicFramer will use AppendIetfConnectionIdsNew instead of
// AppendIetfConnectionId.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_use_new_append_connection_id,
          true)
// If true, QuicStreamSequencerBuffer will switch to a new
// QuicIntervalSet::AddOptimizedForAppend method in OnStreamData().
QUIC_FLAGT(
    bool,
    FLAGS_quic_reloadable_flag_quic_faster_interval_add_in_sequence_buffer,
    true)
// If true, GFE time wait list will send termination packets based on current
// packet's encryption level.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_fix_termination_packets, true)
// If true, stop using AckBundling mode to send ACK, also deprecate ack_queued
// from QuicConnection.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_deprecate_ack_bundling_mode,
          true)
// If both this flag and gfe2_reloadable_flag_quic_deprecate_ack_bundling_mode
// are true, QuicReceivedPacketManager decides when to send ACKs.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_rpm_decides_when_to_send_acks,
          true)
// In QUIC, do not close connection if received an in-order ACK with decreased
// largest_acked.
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_tolerate_reneging, true)
QUIC_FLAGT(
    bool,
    FLAGS_quic_reloadable_flag_quic_validate_packet_number_post_decryption,
    true)
// If this flag and quic_rpm_decides_when_to_send_acks is true, use uber
// received packet manager instead of the single received packet manager.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_use_uber_received_packet_manager,
          true)
// If true and using Leto for QUIC shared-key calculations, GFE will react to a
// failure to contact Leto by sending a REJ containing a fallback ServerConfig,
// allowing the client to continue the handshake.
QUIC_FLAGT(
    bool,
    FLAGS_quic_reloadable_flag_send_quic_fallback_server_config_on_leto_error,
    false)
// If true, GFE will not request private keys when fetching QUIC ServerConfigs
// from Leto.
QUIC_FLAGT(bool,
          FLAGS_quic_restart_flag_dont_fetch_quic_private_keys_from_leto,
          false)
// If true, disable lumpy pacing for low bandwidth flows.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_no_lumpy_pacing_at_low_bw,
          false)
// If true, in BbrSender, always get a bandwidth sample when a packet is acked,
// even if packet.bytes_acked is zero.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_always_get_bw_sample_when_acked,
          true)
// If true, ignore TLPR for retransmission delay when sending pings from ping
// alarm.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_ignore_tlpr_if_sending_ping,
          true)
// If true, non-ASCII QUIC tags are printed as hex instead of integers."
QUIC_FLAGT(bool, FLAGS_quic_reloadable_flag_quic_print_tag_hex, false)
// If true, terminate Google QUIC connections similary as IETF QUIC.
QUIC_FLAGT(bool,
          FLAGS_quic_reloadable_flag_quic_terminate_gquic_connection_as_ietf,
          false)

// Maximum number of tracked packets.
QUIC_FLAGT(int64_t, FLAGS_quic_max_tracked_packet_count, 10000)

// If the bandwidth during ack aggregation is smaller than (estimated
// bandwidth * this flag), consider the current aggregation completed
// and starts a new one.
QUIC_FLAGT(double, FLAGS_quic_ack_aggregation_bandwidth_threshold, 1.0)

// The maximum congestion window in packets.
QUIC_FLAGT(int32_t, FLAGS_quic_max_congestion_window, 2000)

// The default minimum duration for BBRv2-native probes, in milliseconds.
QUIC_FLAGT(int32_t, FLAGS_quic_bbr2_default_probe_bw_base_duration_ms, 2000)

// The default upper bound of the random amount of BBRv2-native
// probes, in milliseconds.
QUIC_FLAGT(int32_t, FLAGS_quic_bbr2_default_probe_bw_max_rand_duration_ms, 1000)

// The default period for entering PROBE_RTT, in milliseconds.
QUIC_FLAGT(int32_t, FLAGS_quic_bbr2_default_probe_rtt_period_ms, 10000)

// The default loss threshold for QUIC BBRv2, should be a value
// between 0 and 1.
QUIC_FLAGT(double, FLAGS_quic_bbr2_default_loss_threshold, 0.02)

// The default minimum number of loss marking events to exit STARTUP.
QUIC_FLAGT(int32_t, FLAGS_quic_bbr2_default_startup_full_loss_count, 8)

// The default fraction of unutilized headroom to try to leave in path
// upon high loss.
QUIC_FLAGT(double, FLAGS_quic_bbr2_default_inflight_hi_headroom, 0.01)

// The default initial value of the max ack height filter's window length.
QUIC_FLAGT(int32_t, FLAGS_quic_bbr2_default_initial_ack_height_filter_window, 10)

// The default minimum number of loss marking events to exit PROBE_UP phase.
QUIC_FLAGT(double, FLAGS_quic_bbr2_default_probe_bw_full_loss_count, 2)

 // Below 1.2Mbps, send 1 packet at once, because one full-sized packet
 // is about 10ms of queueing.
QUIC_FLAGT(int32_t, FLAGS_quic_lumpy_pacing_min_bandwidth_kbps, 1200)

// from quic stream factory defaults seems to be false
QUIC_FLAGT(bool,FLAGS_quic_disable_client_tls_zero_rtt, false)

// If true, use predictable grease settings identifiers and values.
QUIC_FLAGT(bool, FLAGS_quic_enable_http3_grease_randomness, true)

// Anti-amplification factor. Before address validation, server will
// send no more than factor times bytes received.
QUIC_FLAGT(int32_t, FLAGS_quic_anti_amplification_factor, 3)

// no idea if default is correct?
QUIC_FLAGT(bool,FLAGS_quic_disable_server_tls_resumption, false)

// no idea if default is correct?
QUIC_FLAGT(bool,FLAGS_quic_header_size_limit_includes_overhead, false)

// no idea if default is correct?
QUIC_FLAGT(bool,FLAGS_quic_use_lower_server_response_mtu_for_test, false)

// no idea if default is correct?
QUIC_FLAGT(bool,FLAGS_quic_key_update_confidentiality_limit, false)

// no idea if default is correct?
QUIC_FLAGT(int32_t,FLAGS_quic_max_retransmittable_on_wire_ping_count, 20)

// The maximum amount of CRYPTO frame data that can be buffered.
QUIC_FLAGT(int32_t, FLAGS_quic_max_buffered_crypto_bytes, 16 * 1024)

// If set to non-zero, the maximum number of consecutive pings that can be sent
// with aggressive initial retransmittable on wire timeout if there is no new
// data received. After which, the timeout will be exponentially back off until
// exceeds the default ping timeout.
QUIC_FLAGT(int32_t,
          FLAGS_quic_max_aggressive_retransmittable_on_wire_ping_count,
          0)

// If true, use predictable version negotiation versions.
QUIC_FLAGT(bool, FLAGS_quic_disable_version_negotiation_grease_randomness, false)

// no idea if default is correct?
QUIC_FLAGT(bool,FLAGS_quic_enable_chaos_protection, false)
// no idea if default is correct?
QUIC_FLAGT(bool, FLAGS_quic_export_write_path_stats_at_server, false)

// no idea if default is correct?
QUIC_FLAGT(bool, FLAGS_quic_reject_retry_token_in_initial_packet, false)

// The divisor that controls how often MAX_STREAMS frames are sent.
QUIC_FLAGT(int32_t, FLAGS_quic_max_streams_window_divisor, 2)

// no idea what would be the correct value
QUIC_FLAGT(int32_t, FLAGS_quic_max_recent_stateless_reset_addresses, 10)

// no idea what would be the correct value
QUIC_FLAGT(int32_t, FLAGS_quic_recent_stateless_reset_addresses_lifetime_ms, 10 * 1000)

// no idea, but google says 1K
QUIC_FLAGT(int32_t, FLAGS_quic_time_wait_list_max_pending_packets, 1000)

#endif