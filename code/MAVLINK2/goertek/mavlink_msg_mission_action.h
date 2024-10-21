#pragma once
// MESSAGE MISSION_ACTION PACKING

#define MAVLINK_MSG_ID_MISSION_ACTION 4027


typedef struct __mavlink_mission_action_t {
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t mission_action; /*<  0: new mission start; 1: mission continue. 2: mission completed.*/
 uint8_t mission_id; /*<  0: unused; >=1: used*/
} mavlink_mission_action_t;

#define MAVLINK_MSG_ID_MISSION_ACTION_LEN 4
#define MAVLINK_MSG_ID_MISSION_ACTION_MIN_LEN 4
#define MAVLINK_MSG_ID_4027_LEN 4
#define MAVLINK_MSG_ID_4027_MIN_LEN 4

#define MAVLINK_MSG_ID_MISSION_ACTION_CRC 81
#define MAVLINK_MSG_ID_4027_CRC 81



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_ACTION { \
    4027, \
    "MISSION_ACTION", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mission_action_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mission_action_t, target_component) }, \
         { "mission_action", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_action_t, mission_action) }, \
         { "mission_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mission_action_t, mission_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_ACTION { \
    "MISSION_ACTION", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mission_action_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mission_action_t, target_component) }, \
         { "mission_action", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_action_t, mission_action) }, \
         { "mission_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mission_action_t, mission_id) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_action message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param mission_action  0: new mission start; 1: mission continue. 2: mission completed.
 * @param mission_id  0: unused; >=1: used
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_action_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t mission_action, uint8_t mission_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ACTION_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, mission_action);
    _mav_put_uint8_t(buf, 3, mission_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_ACTION_LEN);
#else
    mavlink_mission_action_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.mission_action = mission_action;
    packet.mission_id = mission_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_ACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_ACTION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_ACTION_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_LEN, MAVLINK_MSG_ID_MISSION_ACTION_CRC);
}

/**
 * @brief Pack a mission_action message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param mission_action  0: new mission start; 1: mission continue. 2: mission completed.
 * @param mission_id  0: unused; >=1: used
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_action_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t mission_action,uint8_t mission_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ACTION_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, mission_action);
    _mav_put_uint8_t(buf, 3, mission_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_ACTION_LEN);
#else
    mavlink_mission_action_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.mission_action = mission_action;
    packet.mission_id = mission_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_ACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_ACTION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_ACTION_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_LEN, MAVLINK_MSG_ID_MISSION_ACTION_CRC);
}

/**
 * @brief Encode a mission_action struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_action C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_action_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_action_t* mission_action)
{
    return mavlink_msg_mission_action_pack(system_id, component_id, msg, mission_action->target_system, mission_action->target_component, mission_action->mission_action, mission_action->mission_id);
}

/**
 * @brief Encode a mission_action struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_action C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_action_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mission_action_t* mission_action)
{
    return mavlink_msg_mission_action_pack_chan(system_id, component_id, chan, msg, mission_action->target_system, mission_action->target_component, mission_action->mission_action, mission_action->mission_id);
}

/**
 * @brief Send a mission_action message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param mission_action  0: new mission start; 1: mission continue. 2: mission completed.
 * @param mission_id  0: unused; >=1: used
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mission_action_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t mission_action, uint8_t mission_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ACTION_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, mission_action);
    _mav_put_uint8_t(buf, 3, mission_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ACTION, buf, MAVLINK_MSG_ID_MISSION_ACTION_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_LEN, MAVLINK_MSG_ID_MISSION_ACTION_CRC);
#else
    mavlink_mission_action_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.mission_action = mission_action;
    packet.mission_id = mission_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ACTION, (const char *)&packet, MAVLINK_MSG_ID_MISSION_ACTION_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_LEN, MAVLINK_MSG_ID_MISSION_ACTION_CRC);
#endif
}

/**
 * @brief Send a mission_action message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mission_action_send_struct(mavlink_channel_t chan, const mavlink_mission_action_t* mission_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mission_action_send(chan, mission_action->target_system, mission_action->target_component, mission_action->mission_action, mission_action->mission_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ACTION, (const char *)mission_action, MAVLINK_MSG_ID_MISSION_ACTION_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_LEN, MAVLINK_MSG_ID_MISSION_ACTION_CRC);
#endif
}

#if MAVLINK_MSG_ID_MISSION_ACTION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mission_action_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t mission_action, uint8_t mission_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, mission_action);
    _mav_put_uint8_t(buf, 3, mission_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ACTION, buf, MAVLINK_MSG_ID_MISSION_ACTION_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_LEN, MAVLINK_MSG_ID_MISSION_ACTION_CRC);
#else
    mavlink_mission_action_t *packet = (mavlink_mission_action_t *)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->mission_action = mission_action;
    packet->mission_id = mission_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ACTION, (const char *)packet, MAVLINK_MSG_ID_MISSION_ACTION_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_LEN, MAVLINK_MSG_ID_MISSION_ACTION_CRC);
#endif
}
#endif

#endif

// MESSAGE MISSION_ACTION UNPACKING


/**
 * @brief Get field target_system from mission_action message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_mission_action_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from mission_action message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_mission_action_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field mission_action from mission_action message
 *
 * @return  0: new mission start; 1: mission continue. 2: mission completed.
 */
static inline uint8_t mavlink_msg_mission_action_get_mission_action(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field mission_id from mission_action message
 *
 * @return  0: unused; >=1: used
 */
static inline uint8_t mavlink_msg_mission_action_get_mission_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Decode a mission_action message into a struct
 *
 * @param msg The message to decode
 * @param mission_action C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_action_decode(const mavlink_message_t* msg, mavlink_mission_action_t* mission_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mission_action->target_system = mavlink_msg_mission_action_get_target_system(msg);
    mission_action->target_component = mavlink_msg_mission_action_get_target_component(msg);
    mission_action->mission_action = mavlink_msg_mission_action_get_mission_action(msg);
    mission_action->mission_id = mavlink_msg_mission_action_get_mission_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MISSION_ACTION_LEN? msg->len : MAVLINK_MSG_ID_MISSION_ACTION_LEN;
        memset(mission_action, 0, MAVLINK_MSG_ID_MISSION_ACTION_LEN);
    memcpy(mission_action, _MAV_PAYLOAD(msg), len);
#endif
}
