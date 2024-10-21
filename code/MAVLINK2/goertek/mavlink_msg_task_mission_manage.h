#pragma once
// MESSAGE TASK_MISSION_MANAGE PACKING

#define MAVLINK_MSG_ID_TASK_MISSION_MANAGE 4023


typedef struct __mavlink_task_mission_manage_t {
 float param1; /*<  Reserved*/
 float param2; /*<  Reserved*/
 float param3; /*<  Reserved*/
 float param4; /*<  Reserved*/
 uint16_t seq; /*<  task mission index*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t task_mission_type; /*<  enum(TASK_MISSION_CLASS)*/
 uint8_t cmd; /*<  Task mission manage command*/
} mavlink_task_mission_manage_t;

#define MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN 22
#define MAVLINK_MSG_ID_TASK_MISSION_MANAGE_MIN_LEN 22
#define MAVLINK_MSG_ID_4023_LEN 22
#define MAVLINK_MSG_ID_4023_MIN_LEN 22

#define MAVLINK_MSG_ID_TASK_MISSION_MANAGE_CRC 24
#define MAVLINK_MSG_ID_4023_CRC 24



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_MANAGE { \
    4023, \
    "TASK_MISSION_MANAGE", \
    9, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_task_mission_manage_t, seq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_task_mission_manage_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_task_mission_manage_t, target_component) }, \
         { "task_mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_task_mission_manage_t, task_mission_type) }, \
         { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_task_mission_manage_t, cmd) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_task_mission_manage_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_mission_manage_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_mission_manage_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_task_mission_manage_t, param4) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_MANAGE { \
    "TASK_MISSION_MANAGE", \
    9, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_task_mission_manage_t, seq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_task_mission_manage_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_task_mission_manage_t, target_component) }, \
         { "task_mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_task_mission_manage_t, task_mission_type) }, \
         { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_task_mission_manage_t, cmd) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_task_mission_manage_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_mission_manage_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_mission_manage_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_task_mission_manage_t, param4) }, \
         } \
}
#endif

/**
 * @brief Pack a task_mission_manage message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq  task mission index
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param task_mission_type  enum(TASK_MISSION_CLASS)
 * @param cmd  Task mission manage command
 * @param param1  Reserved
 * @param param2  Reserved
 * @param param3  Reserved
 * @param param4  Reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_manage_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t seq, uint8_t target_system, uint8_t target_component, uint8_t task_mission_type, uint8_t cmd, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint16_t(buf, 16, seq);
    _mav_put_uint8_t(buf, 18, target_system);
    _mav_put_uint8_t(buf, 19, target_component);
    _mav_put_uint8_t(buf, 20, task_mission_type);
    _mav_put_uint8_t(buf, 21, cmd);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN);
#else
    mavlink_task_mission_manage_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.task_mission_type = task_mission_type;
    packet.cmd = cmd;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_MANAGE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_CRC);
}

/**
 * @brief Pack a task_mission_manage message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq  task mission index
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param task_mission_type  enum(TASK_MISSION_CLASS)
 * @param cmd  Task mission manage command
 * @param param1  Reserved
 * @param param2  Reserved
 * @param param3  Reserved
 * @param param4  Reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_manage_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t seq,uint8_t target_system,uint8_t target_component,uint8_t task_mission_type,uint8_t cmd,float param1,float param2,float param3,float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint16_t(buf, 16, seq);
    _mav_put_uint8_t(buf, 18, target_system);
    _mav_put_uint8_t(buf, 19, target_component);
    _mav_put_uint8_t(buf, 20, task_mission_type);
    _mav_put_uint8_t(buf, 21, cmd);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN);
#else
    mavlink_task_mission_manage_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.task_mission_type = task_mission_type;
    packet.cmd = cmd;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_MANAGE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_CRC);
}

/**
 * @brief Encode a task_mission_manage struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_manage C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_manage_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_task_mission_manage_t* task_mission_manage)
{
    return mavlink_msg_task_mission_manage_pack(system_id, component_id, msg, task_mission_manage->seq, task_mission_manage->target_system, task_mission_manage->target_component, task_mission_manage->task_mission_type, task_mission_manage->cmd, task_mission_manage->param1, task_mission_manage->param2, task_mission_manage->param3, task_mission_manage->param4);
}

/**
 * @brief Encode a task_mission_manage struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_manage C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_manage_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_task_mission_manage_t* task_mission_manage)
{
    return mavlink_msg_task_mission_manage_pack_chan(system_id, component_id, chan, msg, task_mission_manage->seq, task_mission_manage->target_system, task_mission_manage->target_component, task_mission_manage->task_mission_type, task_mission_manage->cmd, task_mission_manage->param1, task_mission_manage->param2, task_mission_manage->param3, task_mission_manage->param4);
}

/**
 * @brief Send a task_mission_manage message
 * @param chan MAVLink channel to send the message
 *
 * @param seq  task mission index
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param task_mission_type  enum(TASK_MISSION_CLASS)
 * @param cmd  Task mission manage command
 * @param param1  Reserved
 * @param param2  Reserved
 * @param param3  Reserved
 * @param param4  Reserved
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_mission_manage_send(mavlink_channel_t chan, uint16_t seq, uint8_t target_system, uint8_t target_component, uint8_t task_mission_type, uint8_t cmd, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint16_t(buf, 16, seq);
    _mav_put_uint8_t(buf, 18, target_system);
    _mav_put_uint8_t(buf, 19, target_component);
    _mav_put_uint8_t(buf, 20, task_mission_type);
    _mav_put_uint8_t(buf, 21, cmd);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_MANAGE, buf, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_CRC);
#else
    mavlink_task_mission_manage_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.seq = seq;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.task_mission_type = task_mission_type;
    packet.cmd = cmd;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_MANAGE, (const char *)&packet, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_CRC);
#endif
}

/**
 * @brief Send a task_mission_manage message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_task_mission_manage_send_struct(mavlink_channel_t chan, const mavlink_task_mission_manage_t* task_mission_manage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_task_mission_manage_send(chan, task_mission_manage->seq, task_mission_manage->target_system, task_mission_manage->target_component, task_mission_manage->task_mission_type, task_mission_manage->cmd, task_mission_manage->param1, task_mission_manage->param2, task_mission_manage->param3, task_mission_manage->param4);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_MANAGE, (const char *)task_mission_manage, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_mission_manage_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t seq, uint8_t target_system, uint8_t target_component, uint8_t task_mission_type, uint8_t cmd, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_uint16_t(buf, 16, seq);
    _mav_put_uint8_t(buf, 18, target_system);
    _mav_put_uint8_t(buf, 19, target_component);
    _mav_put_uint8_t(buf, 20, task_mission_type);
    _mav_put_uint8_t(buf, 21, cmd);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_MANAGE, buf, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_CRC);
#else
    mavlink_task_mission_manage_t *packet = (mavlink_task_mission_manage_t *)msgbuf;
    packet->param1 = param1;
    packet->param2 = param2;
    packet->param3 = param3;
    packet->param4 = param4;
    packet->seq = seq;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->task_mission_type = task_mission_type;
    packet->cmd = cmd;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_MANAGE, (const char *)packet, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_MISSION_MANAGE UNPACKING


/**
 * @brief Get field seq from task_mission_manage message
 *
 * @return  task mission index
 */
static inline uint16_t mavlink_msg_task_mission_manage_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field target_system from task_mission_manage message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_task_mission_manage_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field target_component from task_mission_manage message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_task_mission_manage_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field task_mission_type from task_mission_manage message
 *
 * @return  enum(TASK_MISSION_CLASS)
 */
static inline uint8_t mavlink_msg_task_mission_manage_get_task_mission_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field cmd from task_mission_manage message
 *
 * @return  Task mission manage command
 */
static inline uint8_t mavlink_msg_task_mission_manage_get_cmd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field param1 from task_mission_manage message
 *
 * @return  Reserved
 */
static inline float mavlink_msg_task_mission_manage_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param2 from task_mission_manage message
 *
 * @return  Reserved
 */
static inline float mavlink_msg_task_mission_manage_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param3 from task_mission_manage message
 *
 * @return  Reserved
 */
static inline float mavlink_msg_task_mission_manage_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param4 from task_mission_manage message
 *
 * @return  Reserved
 */
static inline float mavlink_msg_task_mission_manage_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a task_mission_manage message into a struct
 *
 * @param msg The message to decode
 * @param task_mission_manage C-struct to decode the message contents into
 */
static inline void mavlink_msg_task_mission_manage_decode(const mavlink_message_t* msg, mavlink_task_mission_manage_t* task_mission_manage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    task_mission_manage->param1 = mavlink_msg_task_mission_manage_get_param1(msg);
    task_mission_manage->param2 = mavlink_msg_task_mission_manage_get_param2(msg);
    task_mission_manage->param3 = mavlink_msg_task_mission_manage_get_param3(msg);
    task_mission_manage->param4 = mavlink_msg_task_mission_manage_get_param4(msg);
    task_mission_manage->seq = mavlink_msg_task_mission_manage_get_seq(msg);
    task_mission_manage->target_system = mavlink_msg_task_mission_manage_get_target_system(msg);
    task_mission_manage->target_component = mavlink_msg_task_mission_manage_get_target_component(msg);
    task_mission_manage->task_mission_type = mavlink_msg_task_mission_manage_get_task_mission_type(msg);
    task_mission_manage->cmd = mavlink_msg_task_mission_manage_get_cmd(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN? msg->len : MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN;
        memset(task_mission_manage, 0, MAVLINK_MSG_ID_TASK_MISSION_MANAGE_LEN);
    memcpy(task_mission_manage, _MAV_PAYLOAD(msg), len);
#endif
}
