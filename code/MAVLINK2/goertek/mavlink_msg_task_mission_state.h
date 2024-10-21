#pragma once
// MESSAGE TASK_MISSION_STATE PACKING

#define MAVLINK_MSG_ID_TASK_MISSION_STATE 4021


typedef struct __mavlink_task_mission_state_t {
 float param1; /*<  Reserved*/
 float param2; /*<  Reserved*/
 float param3; /*<  Reserved*/
 float param4; /*<  Reserved*/
 uint16_t count; /*<  Count of task mission count*/
 uint16_t current_seq; /*<  Current sequence*/
 uint16_t interest_seq; /*<  Interest point sequence*/
 uint8_t task_mission_type; /*<  enum(TASK_MISSION_CLASS)*/
} mavlink_task_mission_state_t;

#define MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN 23
#define MAVLINK_MSG_ID_TASK_MISSION_STATE_MIN_LEN 23
#define MAVLINK_MSG_ID_4021_LEN 23
#define MAVLINK_MSG_ID_4021_MIN_LEN 23

#define MAVLINK_MSG_ID_TASK_MISSION_STATE_CRC 85
#define MAVLINK_MSG_ID_4021_CRC 85



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_STATE { \
    4021, \
    "TASK_MISSION_STATE", \
    8, \
    {  { "count", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_task_mission_state_t, count) }, \
         { "current_seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_task_mission_state_t, current_seq) }, \
         { "interest_seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_task_mission_state_t, interest_seq) }, \
         { "task_mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_task_mission_state_t, task_mission_type) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_task_mission_state_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_mission_state_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_mission_state_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_task_mission_state_t, param4) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_STATE { \
    "TASK_MISSION_STATE", \
    8, \
    {  { "count", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_task_mission_state_t, count) }, \
         { "current_seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_task_mission_state_t, current_seq) }, \
         { "interest_seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_task_mission_state_t, interest_seq) }, \
         { "task_mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_task_mission_state_t, task_mission_type) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_task_mission_state_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_mission_state_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_mission_state_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_task_mission_state_t, param4) }, \
         } \
}
#endif

/**
 * @brief Pack a task_mission_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param count  Count of task mission count
 * @param current_seq  Current sequence
 * @param interest_seq  Interest point sequence
 * @param task_mission_type  enum(TASK_MISSION_CLASS)
 * @param param1  Reserved
 * @param param2  Reserved
 * @param param3  Reserved
 * @param param4  Reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t count, uint16_t current_seq, uint16_t interest_seq, uint8_t task_mission_type, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint16_t(buf, 16, count);
    _mav_put_uint16_t(buf, 18, current_seq);
    _mav_put_uint16_t(buf, 20, interest_seq);
    _mav_put_uint8_t(buf, 22, task_mission_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN);
#else
    mavlink_task_mission_state_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.count = count;
    packet.current_seq = current_seq;
    packet.interest_seq = interest_seq;
    packet.task_mission_type = task_mission_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TASK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_CRC);
}

/**
 * @brief Pack a task_mission_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param count  Count of task mission count
 * @param current_seq  Current sequence
 * @param interest_seq  Interest point sequence
 * @param task_mission_type  enum(TASK_MISSION_CLASS)
 * @param param1  Reserved
 * @param param2  Reserved
 * @param param3  Reserved
 * @param param4  Reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t count,uint16_t current_seq,uint16_t interest_seq,uint8_t task_mission_type,float param1,float param2,float param3,float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint16_t(buf, 16, count);
    _mav_put_uint16_t(buf, 18, current_seq);
    _mav_put_uint16_t(buf, 20, interest_seq);
    _mav_put_uint8_t(buf, 22, task_mission_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN);
#else
    mavlink_task_mission_state_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.count = count;
    packet.current_seq = current_seq;
    packet.interest_seq = interest_seq;
    packet.task_mission_type = task_mission_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TASK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_CRC);
}

/**
 * @brief Encode a task_mission_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_task_mission_state_t* task_mission_state)
{
    return mavlink_msg_task_mission_state_pack(system_id, component_id, msg, task_mission_state->count, task_mission_state->current_seq, task_mission_state->interest_seq, task_mission_state->task_mission_type, task_mission_state->param1, task_mission_state->param2, task_mission_state->param3, task_mission_state->param4);
}

/**
 * @brief Encode a task_mission_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_task_mission_state_t* task_mission_state)
{
    return mavlink_msg_task_mission_state_pack_chan(system_id, component_id, chan, msg, task_mission_state->count, task_mission_state->current_seq, task_mission_state->interest_seq, task_mission_state->task_mission_type, task_mission_state->param1, task_mission_state->param2, task_mission_state->param3, task_mission_state->param4);
}

/**
 * @brief Send a task_mission_state message
 * @param chan MAVLink channel to send the message
 *
 * @param count  Count of task mission count
 * @param current_seq  Current sequence
 * @param interest_seq  Interest point sequence
 * @param task_mission_type  enum(TASK_MISSION_CLASS)
 * @param param1  Reserved
 * @param param2  Reserved
 * @param param3  Reserved
 * @param param4  Reserved
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_mission_state_send(mavlink_channel_t chan, uint16_t count, uint16_t current_seq, uint16_t interest_seq, uint8_t task_mission_type, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint16_t(buf, 16, count);
    _mav_put_uint16_t(buf, 18, current_seq);
    _mav_put_uint16_t(buf, 20, interest_seq);
    _mav_put_uint8_t(buf, 22, task_mission_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_STATE, buf, MAVLINK_MSG_ID_TASK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_CRC);
#else
    mavlink_task_mission_state_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.count = count;
    packet.current_seq = current_seq;
    packet.interest_seq = interest_seq;
    packet.task_mission_type = task_mission_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_STATE, (const char *)&packet, MAVLINK_MSG_ID_TASK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_CRC);
#endif
}

/**
 * @brief Send a task_mission_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_task_mission_state_send_struct(mavlink_channel_t chan, const mavlink_task_mission_state_t* task_mission_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_task_mission_state_send(chan, task_mission_state->count, task_mission_state->current_seq, task_mission_state->interest_seq, task_mission_state->task_mission_type, task_mission_state->param1, task_mission_state->param2, task_mission_state->param3, task_mission_state->param4);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_STATE, (const char *)task_mission_state, MAVLINK_MSG_ID_TASK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_mission_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t count, uint16_t current_seq, uint16_t interest_seq, uint8_t task_mission_type, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint16_t(buf, 16, count);
    _mav_put_uint16_t(buf, 18, current_seq);
    _mav_put_uint16_t(buf, 20, interest_seq);
    _mav_put_uint8_t(buf, 22, task_mission_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_STATE, buf, MAVLINK_MSG_ID_TASK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_CRC);
#else
    mavlink_task_mission_state_t *packet = (mavlink_task_mission_state_t *)msgbuf;
    packet->param1 = param1;
    packet->param2 = param2;
    packet->param3 = param3;
    packet->param4 = param4;
    packet->count = count;
    packet->current_seq = current_seq;
    packet->interest_seq = interest_seq;
    packet->task_mission_type = task_mission_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_STATE, (const char *)packet, MAVLINK_MSG_ID_TASK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN, MAVLINK_MSG_ID_TASK_MISSION_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_MISSION_STATE UNPACKING


/**
 * @brief Get field count from task_mission_state message
 *
 * @return  Count of task mission count
 */
static inline uint16_t mavlink_msg_task_mission_state_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field current_seq from task_mission_state message
 *
 * @return  Current sequence
 */
static inline uint16_t mavlink_msg_task_mission_state_get_current_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field interest_seq from task_mission_state message
 *
 * @return  Interest point sequence
 */
static inline uint16_t mavlink_msg_task_mission_state_get_interest_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field task_mission_type from task_mission_state message
 *
 * @return  enum(TASK_MISSION_CLASS)
 */
static inline uint8_t mavlink_msg_task_mission_state_get_task_mission_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field param1 from task_mission_state message
 *
 * @return  Reserved
 */
static inline float mavlink_msg_task_mission_state_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param2 from task_mission_state message
 *
 * @return  Reserved
 */
static inline float mavlink_msg_task_mission_state_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param3 from task_mission_state message
 *
 * @return  Reserved
 */
static inline float mavlink_msg_task_mission_state_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param4 from task_mission_state message
 *
 * @return  Reserved
 */
static inline float mavlink_msg_task_mission_state_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a task_mission_state message into a struct
 *
 * @param msg The message to decode
 * @param task_mission_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_task_mission_state_decode(const mavlink_message_t* msg, mavlink_task_mission_state_t* task_mission_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    task_mission_state->param1 = mavlink_msg_task_mission_state_get_param1(msg);
    task_mission_state->param2 = mavlink_msg_task_mission_state_get_param2(msg);
    task_mission_state->param3 = mavlink_msg_task_mission_state_get_param3(msg);
    task_mission_state->param4 = mavlink_msg_task_mission_state_get_param4(msg);
    task_mission_state->count = mavlink_msg_task_mission_state_get_count(msg);
    task_mission_state->current_seq = mavlink_msg_task_mission_state_get_current_seq(msg);
    task_mission_state->interest_seq = mavlink_msg_task_mission_state_get_interest_seq(msg);
    task_mission_state->task_mission_type = mavlink_msg_task_mission_state_get_task_mission_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN? msg->len : MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN;
        memset(task_mission_state, 0, MAVLINK_MSG_ID_TASK_MISSION_STATE_LEN);
    memcpy(task_mission_state, _MAV_PAYLOAD(msg), len);
#endif
}
