#pragma once
// MESSAGE EXPOSURE_EVENT_ACK PACKING

#define MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK 4019


typedef struct __mavlink_exposure_event_ack_t {
 double lat; /*<  [deg] Latitude (WGS84)*/
 double lon; /*<  [deg] Longitude (WGS84)*/
 uint32_t week; /*<  week of event, 0 for unknown*/
 uint32_t second; /*<  second of event, 0 for unknown*/
 uint32_t subsecond; /*<  nano second of event, 0 for unknown*/
 int32_t alt; /*<  [mm] Altitude (MSL). Positive for up*/
 float lat_err; /*<  [m] Latitude error*/
 float lon_err; /*<  [m] Longitude error*/
 float alt_err; /*<  [m] Altitude error*/
 float roll; /*<  [rad] Roll angle (-pi..+pi)*/
 float pitch; /*<  [rad] Pitch angle (-pi..+pi)*/
 float yaw; /*<  [rad] Yaw angle (-pi..+pi)*/
} mavlink_exposure_event_ack_t;

#define MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN 56
#define MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_MIN_LEN 56
#define MAVLINK_MSG_ID_4019_LEN 56
#define MAVLINK_MSG_ID_4019_MIN_LEN 56

#define MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_CRC 173
#define MAVLINK_MSG_ID_4019_CRC 173



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EXPOSURE_EVENT_ACK { \
    4019, \
    "EXPOSURE_EVENT_ACK", \
    12, \
    {  { "week", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_exposure_event_ack_t, week) }, \
         { "second", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_exposure_event_ack_t, second) }, \
         { "subsecond", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_exposure_event_ack_t, subsecond) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_exposure_event_ack_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_exposure_event_ack_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_exposure_event_ack_t, alt) }, \
         { "lat_err", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_exposure_event_ack_t, lat_err) }, \
         { "lon_err", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_exposure_event_ack_t, lon_err) }, \
         { "alt_err", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_exposure_event_ack_t, alt_err) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_exposure_event_ack_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_exposure_event_ack_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_exposure_event_ack_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EXPOSURE_EVENT_ACK { \
    "EXPOSURE_EVENT_ACK", \
    12, \
    {  { "week", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_exposure_event_ack_t, week) }, \
         { "second", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_exposure_event_ack_t, second) }, \
         { "subsecond", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_exposure_event_ack_t, subsecond) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_exposure_event_ack_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_exposure_event_ack_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_exposure_event_ack_t, alt) }, \
         { "lat_err", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_exposure_event_ack_t, lat_err) }, \
         { "lon_err", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_exposure_event_ack_t, lon_err) }, \
         { "alt_err", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_exposure_event_ack_t, alt_err) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_exposure_event_ack_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_exposure_event_ack_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_exposure_event_ack_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a exposure_event_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param week  week of event, 0 for unknown
 * @param second  second of event, 0 for unknown
 * @param subsecond  nano second of event, 0 for unknown
 * @param lat  [deg] Latitude (WGS84)
 * @param lon  [deg] Longitude (WGS84)
 * @param alt  [mm] Altitude (MSL). Positive for up
 * @param lat_err  [m] Latitude error
 * @param lon_err  [m] Longitude error
 * @param alt_err  [m] Altitude error
 * @param roll  [rad] Roll angle (-pi..+pi)
 * @param pitch  [rad] Pitch angle (-pi..+pi)
 * @param yaw  [rad] Yaw angle (-pi..+pi)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_exposure_event_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t week, uint32_t second, uint32_t subsecond, double lat, double lon, int32_t alt, float lat_err, float lon_err, float alt_err, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN];
    _mav_put_double(buf, 0, lat);
    _mav_put_double(buf, 8, lon);
    _mav_put_uint32_t(buf, 16, week);
    _mav_put_uint32_t(buf, 20, second);
    _mav_put_uint32_t(buf, 24, subsecond);
    _mav_put_int32_t(buf, 28, alt);
    _mav_put_float(buf, 32, lat_err);
    _mav_put_float(buf, 36, lon_err);
    _mav_put_float(buf, 40, alt_err);
    _mav_put_float(buf, 44, roll);
    _mav_put_float(buf, 48, pitch);
    _mav_put_float(buf, 52, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN);
#else
    mavlink_exposure_event_ack_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.week = week;
    packet.second = second;
    packet.subsecond = subsecond;
    packet.alt = alt;
    packet.lat_err = lat_err;
    packet.lon_err = lon_err;
    packet.alt_err = alt_err;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_MIN_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_CRC);
}

/**
 * @brief Pack a exposure_event_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param week  week of event, 0 for unknown
 * @param second  second of event, 0 for unknown
 * @param subsecond  nano second of event, 0 for unknown
 * @param lat  [deg] Latitude (WGS84)
 * @param lon  [deg] Longitude (WGS84)
 * @param alt  [mm] Altitude (MSL). Positive for up
 * @param lat_err  [m] Latitude error
 * @param lon_err  [m] Longitude error
 * @param alt_err  [m] Altitude error
 * @param roll  [rad] Roll angle (-pi..+pi)
 * @param pitch  [rad] Pitch angle (-pi..+pi)
 * @param yaw  [rad] Yaw angle (-pi..+pi)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_exposure_event_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t week,uint32_t second,uint32_t subsecond,double lat,double lon,int32_t alt,float lat_err,float lon_err,float alt_err,float roll,float pitch,float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN];
    _mav_put_double(buf, 0, lat);
    _mav_put_double(buf, 8, lon);
    _mav_put_uint32_t(buf, 16, week);
    _mav_put_uint32_t(buf, 20, second);
    _mav_put_uint32_t(buf, 24, subsecond);
    _mav_put_int32_t(buf, 28, alt);
    _mav_put_float(buf, 32, lat_err);
    _mav_put_float(buf, 36, lon_err);
    _mav_put_float(buf, 40, alt_err);
    _mav_put_float(buf, 44, roll);
    _mav_put_float(buf, 48, pitch);
    _mav_put_float(buf, 52, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN);
#else
    mavlink_exposure_event_ack_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.week = week;
    packet.second = second;
    packet.subsecond = subsecond;
    packet.alt = alt;
    packet.lat_err = lat_err;
    packet.lon_err = lon_err;
    packet.alt_err = alt_err;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_MIN_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_CRC);
}

/**
 * @brief Encode a exposure_event_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param exposure_event_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_exposure_event_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_exposure_event_ack_t* exposure_event_ack)
{
    return mavlink_msg_exposure_event_ack_pack(system_id, component_id, msg, exposure_event_ack->week, exposure_event_ack->second, exposure_event_ack->subsecond, exposure_event_ack->lat, exposure_event_ack->lon, exposure_event_ack->alt, exposure_event_ack->lat_err, exposure_event_ack->lon_err, exposure_event_ack->alt_err, exposure_event_ack->roll, exposure_event_ack->pitch, exposure_event_ack->yaw);
}

/**
 * @brief Encode a exposure_event_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param exposure_event_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_exposure_event_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_exposure_event_ack_t* exposure_event_ack)
{
    return mavlink_msg_exposure_event_ack_pack_chan(system_id, component_id, chan, msg, exposure_event_ack->week, exposure_event_ack->second, exposure_event_ack->subsecond, exposure_event_ack->lat, exposure_event_ack->lon, exposure_event_ack->alt, exposure_event_ack->lat_err, exposure_event_ack->lon_err, exposure_event_ack->alt_err, exposure_event_ack->roll, exposure_event_ack->pitch, exposure_event_ack->yaw);
}

/**
 * @brief Send a exposure_event_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param week  week of event, 0 for unknown
 * @param second  second of event, 0 for unknown
 * @param subsecond  nano second of event, 0 for unknown
 * @param lat  [deg] Latitude (WGS84)
 * @param lon  [deg] Longitude (WGS84)
 * @param alt  [mm] Altitude (MSL). Positive for up
 * @param lat_err  [m] Latitude error
 * @param lon_err  [m] Longitude error
 * @param alt_err  [m] Altitude error
 * @param roll  [rad] Roll angle (-pi..+pi)
 * @param pitch  [rad] Pitch angle (-pi..+pi)
 * @param yaw  [rad] Yaw angle (-pi..+pi)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_exposure_event_ack_send(mavlink_channel_t chan, uint32_t week, uint32_t second, uint32_t subsecond, double lat, double lon, int32_t alt, float lat_err, float lon_err, float alt_err, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN];
    _mav_put_double(buf, 0, lat);
    _mav_put_double(buf, 8, lon);
    _mav_put_uint32_t(buf, 16, week);
    _mav_put_uint32_t(buf, 20, second);
    _mav_put_uint32_t(buf, 24, subsecond);
    _mav_put_int32_t(buf, 28, alt);
    _mav_put_float(buf, 32, lat_err);
    _mav_put_float(buf, 36, lon_err);
    _mav_put_float(buf, 40, alt_err);
    _mav_put_float(buf, 44, roll);
    _mav_put_float(buf, 48, pitch);
    _mav_put_float(buf, 52, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK, buf, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_MIN_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_CRC);
#else
    mavlink_exposure_event_ack_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.week = week;
    packet.second = second;
    packet.subsecond = subsecond;
    packet.alt = alt;
    packet.lat_err = lat_err;
    packet.lon_err = lon_err;
    packet.alt_err = alt_err;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK, (const char *)&packet, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_MIN_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_CRC);
#endif
}

/**
 * @brief Send a exposure_event_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_exposure_event_ack_send_struct(mavlink_channel_t chan, const mavlink_exposure_event_ack_t* exposure_event_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_exposure_event_ack_send(chan, exposure_event_ack->week, exposure_event_ack->second, exposure_event_ack->subsecond, exposure_event_ack->lat, exposure_event_ack->lon, exposure_event_ack->alt, exposure_event_ack->lat_err, exposure_event_ack->lon_err, exposure_event_ack->alt_err, exposure_event_ack->roll, exposure_event_ack->pitch, exposure_event_ack->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK, (const char *)exposure_event_ack, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_MIN_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_exposure_event_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t week, uint32_t second, uint32_t subsecond, double lat, double lon, int32_t alt, float lat_err, float lon_err, float alt_err, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_double(buf, 0, lat);
    _mav_put_double(buf, 8, lon);
    _mav_put_uint32_t(buf, 16, week);
    _mav_put_uint32_t(buf, 20, second);
    _mav_put_uint32_t(buf, 24, subsecond);
    _mav_put_int32_t(buf, 28, alt);
    _mav_put_float(buf, 32, lat_err);
    _mav_put_float(buf, 36, lon_err);
    _mav_put_float(buf, 40, alt_err);
    _mav_put_float(buf, 44, roll);
    _mav_put_float(buf, 48, pitch);
    _mav_put_float(buf, 52, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK, buf, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_MIN_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_CRC);
#else
    mavlink_exposure_event_ack_t *packet = (mavlink_exposure_event_ack_t *)msgbuf;
    packet->lat = lat;
    packet->lon = lon;
    packet->week = week;
    packet->second = second;
    packet->subsecond = subsecond;
    packet->alt = alt;
    packet->lat_err = lat_err;
    packet->lon_err = lon_err;
    packet->alt_err = alt_err;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK, (const char *)packet, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_MIN_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE EXPOSURE_EVENT_ACK UNPACKING


/**
 * @brief Get field week from exposure_event_ack message
 *
 * @return  week of event, 0 for unknown
 */
static inline uint32_t mavlink_msg_exposure_event_ack_get_week(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field second from exposure_event_ack message
 *
 * @return  second of event, 0 for unknown
 */
static inline uint32_t mavlink_msg_exposure_event_ack_get_second(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field subsecond from exposure_event_ack message
 *
 * @return  nano second of event, 0 for unknown
 */
static inline uint32_t mavlink_msg_exposure_event_ack_get_subsecond(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field lat from exposure_event_ack message
 *
 * @return  [deg] Latitude (WGS84)
 */
static inline double mavlink_msg_exposure_event_ack_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  0);
}

/**
 * @brief Get field lon from exposure_event_ack message
 *
 * @return  [deg] Longitude (WGS84)
 */
static inline double mavlink_msg_exposure_event_ack_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field alt from exposure_event_ack message
 *
 * @return  [mm] Altitude (MSL). Positive for up
 */
static inline int32_t mavlink_msg_exposure_event_ack_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field lat_err from exposure_event_ack message
 *
 * @return  [m] Latitude error
 */
static inline float mavlink_msg_exposure_event_ack_get_lat_err(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field lon_err from exposure_event_ack message
 *
 * @return  [m] Longitude error
 */
static inline float mavlink_msg_exposure_event_ack_get_lon_err(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field alt_err from exposure_event_ack message
 *
 * @return  [m] Altitude error
 */
static inline float mavlink_msg_exposure_event_ack_get_alt_err(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field roll from exposure_event_ack message
 *
 * @return  [rad] Roll angle (-pi..+pi)
 */
static inline float mavlink_msg_exposure_event_ack_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field pitch from exposure_event_ack message
 *
 * @return  [rad] Pitch angle (-pi..+pi)
 */
static inline float mavlink_msg_exposure_event_ack_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field yaw from exposure_event_ack message
 *
 * @return  [rad] Yaw angle (-pi..+pi)
 */
static inline float mavlink_msg_exposure_event_ack_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Decode a exposure_event_ack message into a struct
 *
 * @param msg The message to decode
 * @param exposure_event_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_exposure_event_ack_decode(const mavlink_message_t* msg, mavlink_exposure_event_ack_t* exposure_event_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    exposure_event_ack->lat = mavlink_msg_exposure_event_ack_get_lat(msg);
    exposure_event_ack->lon = mavlink_msg_exposure_event_ack_get_lon(msg);
    exposure_event_ack->week = mavlink_msg_exposure_event_ack_get_week(msg);
    exposure_event_ack->second = mavlink_msg_exposure_event_ack_get_second(msg);
    exposure_event_ack->subsecond = mavlink_msg_exposure_event_ack_get_subsecond(msg);
    exposure_event_ack->alt = mavlink_msg_exposure_event_ack_get_alt(msg);
    exposure_event_ack->lat_err = mavlink_msg_exposure_event_ack_get_lat_err(msg);
    exposure_event_ack->lon_err = mavlink_msg_exposure_event_ack_get_lon_err(msg);
    exposure_event_ack->alt_err = mavlink_msg_exposure_event_ack_get_alt_err(msg);
    exposure_event_ack->roll = mavlink_msg_exposure_event_ack_get_roll(msg);
    exposure_event_ack->pitch = mavlink_msg_exposure_event_ack_get_pitch(msg);
    exposure_event_ack->yaw = mavlink_msg_exposure_event_ack_get_yaw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN? msg->len : MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN;
        memset(exposure_event_ack, 0, MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_LEN);
    memcpy(exposure_event_ack, _MAV_PAYLOAD(msg), len);
#endif
}
