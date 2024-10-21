#pragma once
// MESSAGE TASK_MISSION_REQUEST PACKING

#define MAVLINK_MSG_ID_TASK_MISSION_REQUEST 4024


typedef struct __mavlink_task_mission_request_t {
 uint16_t seq; /*<  task mission index*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t task_mission_type; /*<  enum(TASK_MISSION_CLASS)*/
} mavlink_task_mission_request_t;

#define MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN 5
#define MAVLINK_MSG_ID_TASK_MISSION_REQUEST_MIN_LEN 5
#define MAVLINK_MSG_ID_4024_LEN 5
#define MAVLINK_MSG_ID_4024_MIN_LEN 5

#define MAVLINK_MSG_ID_TASK_MISSION_REQUEST_CRC 235
#define MAVLINK_MSG_ID_4024_CRC 235



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_REQUEST { \
    4024, \
    "TASK_MISSION_REQUEST", \
    4, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_task_mission_request_t, seq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_task_mission_request_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_task_mission_request_t, target_component) }, \
         { "task_mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_task_mission_request_t, task_mission_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_REQUEST { \
    "TASK_MISSION_REQUEST", \
    4, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_task_mission_request_t, seq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_task_mission_request_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_task_mission_request_t, target_component) }, \
         { "task_mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_task_mission_request_t, task_mission_type) }, \
         } \
}
#endif

/**
 * @brief Pack a task_mission_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq  task mission index
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param task_mission_type  enum(TASK_MISSION_CLASS)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t seq, uint8_t target_system, uint8_t target_component, uint8_t task_mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN];
    _mav_put_uint16_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, task_mission_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN);
#else
    mavlink_task_mission_request_t packet;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.task_mission_type = task_mission_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_CRC);
}

/**
 * @brief Pack a task_mission_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq  task mission index
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param task_mission_type  enum(TASK_MISSION_CLASS)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t seq,uint8_t target_system,uint8_t target_component,uint8_t task_mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN];
    _mav_put_uint16_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, task_mission_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN);
#else
    mavlink_task_mission_request_t packet;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.task_mission_type = task_mission_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_CRC);
}

/**
 * @brief Encode a task_mission_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_task_mission_request_t* task_mission_request)
{
    return mavlink_msg_task_mission_request_pack(system_id, component_id, msg, task_mission_request->seq, task_mission_request->target_system, task_mission_request->target_component, task_mission_request->task_mission_type);
}

/**
 * @brief Encode a task_mission_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_task_mission_request_t* task_mission_request)
{
    return mavlink_msg_task_mission_request_pack_chan(system_id, component_id, chan, msg, task_mission_request->seq, task_mission_request->target_system, task_mission_request->target_component, task_mission_request->task_mission_type);
}

/**
 * @brief Send a task_mission_request message
 * @param chan MAVLink channel to send the message
 *
 * @param seq  task mission index
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param task_mission_type  enum(TASK_MISSION_CLASS)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_mission_request_send(mavlink_channel_t chan, uint16_t seq, uint8_t target_system, uint8_t target_component, uint8_t task_mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN];
    _mav_put_uint16_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, task_mission_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_REQUEST, buf, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_CRC);
#else
    mavlink_task_mission_request_t packet;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.task_mission_type = task_mission_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_CRC);
#endif
}

/**
 * @brief Send a task_mission_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_task_mission_request_send_struct(mavlink_channel_t chan, const mavlink_task_mission_request_t* task_mission_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_task_mission_request_send(chan, task_mission_request->seq, task_mission_request->target_system, task_mission_request->target_component, task_mission_request->task_mission_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_REQUEST, (const char *)task_mission_request, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_mission_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t seq, uint8_t target_system, uint8_t target_component, uint8_t task_mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, task_mission_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_REQUEST, buf, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_CRC);
#else
    mavlink_task_mission_request_t *packet = (mavlink_task_mission_request_t *)msgbuf;
    packet->seq = seq;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->task_mission_type = task_mission_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_REQUEST, (const char *)packet, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_MISSION_REQUEST UNPACKING


/**
 * @brief Get field seq from task_mission_request message
 *
 * @return  task mission index
 */
static inline uint16_t mavlink_msg_task_mission_request_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field target_system from task_mission_request message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_task_mission_request_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field target_component from task_mission_request message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_task_mission_request_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field task_mission_type from task_mission_request message
 *
 * @return  enum(TASK_MISSION_CLASS)
 */
static inline uint8_t mavlink_msg_task_mission_request_get_task_mission_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a task_mission_request message into a struct
 *
 * @param msg The message to decode
 * @param task_mission_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_task_mission_request_decode(const mavlink_message_t* msg, mavlink_task_mission_request_t* task_mission_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    task_mission_request->seq = mavlink_msg_task_mission_request_get_seq(msg);
    task_mission_request->target_system = mavlink_msg_task_mission_request_get_target_system(msg);
    task_mission_request->target_component = mavlink_msg_task_mission_request_get_target_component(msg);
    task_mission_request->task_mission_type = mavlink_msg_task_mission_request_get_task_mission_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN;
        memset(task_mission_request, 0, MAVLINK_MSG_ID_TASK_MISSION_REQUEST_LEN);
    memcpy(task_mission_request, _MAV_PAYLOAD(msg), len);
#endif
}
