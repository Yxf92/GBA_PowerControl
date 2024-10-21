#pragma once
// MESSAGE TASK_MISSION_ACK PACKING

#define MAVLINK_MSG_ID_TASK_MISSION_ACK 4020


typedef struct __mavlink_task_mission_ack_t {
 uint32_t index; /*<  The index number of the task mission item*/
 float param1; /*<  Reserved */
 float param2; /*<  Reserved */
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t result; /*<  Ack result, see enum(MAV_TASK_RESULT)*/
 uint8_t task_mission_type; /*<  Returned task mission type, see enum (TASK_MISSION_TYPE)*/
} mavlink_task_mission_ack_t;

#define MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN 16
#define MAVLINK_MSG_ID_TASK_MISSION_ACK_MIN_LEN 16
#define MAVLINK_MSG_ID_4020_LEN 16
#define MAVLINK_MSG_ID_4020_MIN_LEN 16

#define MAVLINK_MSG_ID_TASK_MISSION_ACK_CRC 113
#define MAVLINK_MSG_ID_4020_CRC 113



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_ACK { \
    4020, \
    "TASK_MISSION_ACK", \
    7, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_task_mission_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_task_mission_ack_t, target_component) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_task_mission_ack_t, result) }, \
         { "task_mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_task_mission_ack_t, task_mission_type) }, \
         { "index", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_task_mission_ack_t, index) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_mission_ack_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_mission_ack_t, param2) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_ACK { \
    "TASK_MISSION_ACK", \
    7, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_task_mission_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_task_mission_ack_t, target_component) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_task_mission_ack_t, result) }, \
         { "task_mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_task_mission_ack_t, task_mission_type) }, \
         { "index", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_task_mission_ack_t, index) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_mission_ack_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_mission_ack_t, param2) }, \
         } \
}
#endif

/**
 * @brief Pack a task_mission_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param result  Ack result, see enum(MAV_TASK_RESULT)
 * @param task_mission_type  Returned task mission type, see enum (TASK_MISSION_TYPE)
 * @param index  The index number of the task mission item
 * @param param1  Reserved 
 * @param param2  Reserved 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t result, uint8_t task_mission_type, uint32_t index, float param1, float param2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN];
    _mav_put_uint32_t(buf, 0, index);
    _mav_put_float(buf, 4, param1);
    _mav_put_float(buf, 8, param2);
    _mav_put_uint8_t(buf, 12, target_system);
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, result);
    _mav_put_uint8_t(buf, 15, task_mission_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN);
#else
    mavlink_task_mission_ack_t packet;
    packet.index = index;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;
    packet.task_mission_type = task_mission_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TASK_MISSION_ACK_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_CRC);
}

/**
 * @brief Pack a task_mission_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param result  Ack result, see enum(MAV_TASK_RESULT)
 * @param task_mission_type  Returned task mission type, see enum (TASK_MISSION_TYPE)
 * @param index  The index number of the task mission item
 * @param param1  Reserved 
 * @param param2  Reserved 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t result,uint8_t task_mission_type,uint32_t index,float param1,float param2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN];
    _mav_put_uint32_t(buf, 0, index);
    _mav_put_float(buf, 4, param1);
    _mav_put_float(buf, 8, param2);
    _mav_put_uint8_t(buf, 12, target_system);
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, result);
    _mav_put_uint8_t(buf, 15, task_mission_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN);
#else
    mavlink_task_mission_ack_t packet;
    packet.index = index;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;
    packet.task_mission_type = task_mission_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TASK_MISSION_ACK_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_CRC);
}

/**
 * @brief Encode a task_mission_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_task_mission_ack_t* task_mission_ack)
{
    return mavlink_msg_task_mission_ack_pack(system_id, component_id, msg, task_mission_ack->target_system, task_mission_ack->target_component, task_mission_ack->result, task_mission_ack->task_mission_type, task_mission_ack->index, task_mission_ack->param1, task_mission_ack->param2);
}

/**
 * @brief Encode a task_mission_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_task_mission_ack_t* task_mission_ack)
{
    return mavlink_msg_task_mission_ack_pack_chan(system_id, component_id, chan, msg, task_mission_ack->target_system, task_mission_ack->target_component, task_mission_ack->result, task_mission_ack->task_mission_type, task_mission_ack->index, task_mission_ack->param1, task_mission_ack->param2);
}

/**
 * @brief Send a task_mission_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param result  Ack result, see enum(MAV_TASK_RESULT)
 * @param task_mission_type  Returned task mission type, see enum (TASK_MISSION_TYPE)
 * @param index  The index number of the task mission item
 * @param param1  Reserved 
 * @param param2  Reserved 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_mission_ack_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t result, uint8_t task_mission_type, uint32_t index, float param1, float param2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN];
    _mav_put_uint32_t(buf, 0, index);
    _mav_put_float(buf, 4, param1);
    _mav_put_float(buf, 8, param2);
    _mav_put_uint8_t(buf, 12, target_system);
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, result);
    _mav_put_uint8_t(buf, 15, task_mission_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_ACK, buf, MAVLINK_MSG_ID_TASK_MISSION_ACK_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_CRC);
#else
    mavlink_task_mission_ack_t packet;
    packet.index = index;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;
    packet.task_mission_type = task_mission_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_ACK, (const char *)&packet, MAVLINK_MSG_ID_TASK_MISSION_ACK_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_CRC);
#endif
}

/**
 * @brief Send a task_mission_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_task_mission_ack_send_struct(mavlink_channel_t chan, const mavlink_task_mission_ack_t* task_mission_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_task_mission_ack_send(chan, task_mission_ack->target_system, task_mission_ack->target_component, task_mission_ack->result, task_mission_ack->task_mission_type, task_mission_ack->index, task_mission_ack->param1, task_mission_ack->param2);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_ACK, (const char *)task_mission_ack, MAVLINK_MSG_ID_TASK_MISSION_ACK_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_mission_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t result, uint8_t task_mission_type, uint32_t index, float param1, float param2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, index);
    _mav_put_float(buf, 4, param1);
    _mav_put_float(buf, 8, param2);
    _mav_put_uint8_t(buf, 12, target_system);
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, result);
    _mav_put_uint8_t(buf, 15, task_mission_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_ACK, buf, MAVLINK_MSG_ID_TASK_MISSION_ACK_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_CRC);
#else
    mavlink_task_mission_ack_t *packet = (mavlink_task_mission_ack_t *)msgbuf;
    packet->index = index;
    packet->param1 = param1;
    packet->param2 = param2;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->result = result;
    packet->task_mission_type = task_mission_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_ACK, (const char *)packet, MAVLINK_MSG_ID_TASK_MISSION_ACK_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN, MAVLINK_MSG_ID_TASK_MISSION_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_MISSION_ACK UNPACKING


/**
 * @brief Get field target_system from task_mission_ack message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_task_mission_ack_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field target_component from task_mission_ack message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_task_mission_ack_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field result from task_mission_ack message
 *
 * @return  Ack result, see enum(MAV_TASK_RESULT)
 */
static inline uint8_t mavlink_msg_task_mission_ack_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field task_mission_type from task_mission_ack message
 *
 * @return  Returned task mission type, see enum (TASK_MISSION_TYPE)
 */
static inline uint8_t mavlink_msg_task_mission_ack_get_task_mission_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field index from task_mission_ack message
 *
 * @return  The index number of the task mission item
 */
static inline uint32_t mavlink_msg_task_mission_ack_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field param1 from task_mission_ack message
 *
 * @return  Reserved 
 */
static inline float mavlink_msg_task_mission_ack_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param2 from task_mission_ack message
 *
 * @return  Reserved 
 */
static inline float mavlink_msg_task_mission_ack_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a task_mission_ack message into a struct
 *
 * @param msg The message to decode
 * @param task_mission_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_task_mission_ack_decode(const mavlink_message_t* msg, mavlink_task_mission_ack_t* task_mission_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    task_mission_ack->index = mavlink_msg_task_mission_ack_get_index(msg);
    task_mission_ack->param1 = mavlink_msg_task_mission_ack_get_param1(msg);
    task_mission_ack->param2 = mavlink_msg_task_mission_ack_get_param2(msg);
    task_mission_ack->target_system = mavlink_msg_task_mission_ack_get_target_system(msg);
    task_mission_ack->target_component = mavlink_msg_task_mission_ack_get_target_component(msg);
    task_mission_ack->result = mavlink_msg_task_mission_ack_get_result(msg);
    task_mission_ack->task_mission_type = mavlink_msg_task_mission_ack_get_task_mission_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN? msg->len : MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN;
        memset(task_mission_ack, 0, MAVLINK_MSG_ID_TASK_MISSION_ACK_LEN);
    memcpy(task_mission_ack, _MAV_PAYLOAD(msg), len);
#endif
}
