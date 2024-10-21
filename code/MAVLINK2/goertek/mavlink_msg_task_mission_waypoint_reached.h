#pragma once
// MESSAGE TASK_MISSION_WAYPOINT_REACHED PACKING

#define MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED 4025


typedef struct __mavlink_task_mission_waypoint_reached_t {
 uint16_t seq; /*<  task mission index*/
} mavlink_task_mission_waypoint_reached_t;

#define MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN 2
#define MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_MIN_LEN 2
#define MAVLINK_MSG_ID_4025_LEN 2
#define MAVLINK_MSG_ID_4025_MIN_LEN 2

#define MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_CRC 128
#define MAVLINK_MSG_ID_4025_CRC 128



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_WAYPOINT_REACHED { \
    4025, \
    "TASK_MISSION_WAYPOINT_REACHED", \
    1, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_task_mission_waypoint_reached_t, seq) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_WAYPOINT_REACHED { \
    "TASK_MISSION_WAYPOINT_REACHED", \
    1, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_task_mission_waypoint_reached_t, seq) }, \
         } \
}
#endif

/**
 * @brief Pack a task_mission_waypoint_reached message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq  task mission index
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_waypoint_reached_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN];
    _mav_put_uint16_t(buf, 0, seq);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN);
#else
    mavlink_task_mission_waypoint_reached_t packet;
    packet.seq = seq;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_CRC);
}

/**
 * @brief Pack a task_mission_waypoint_reached message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq  task mission index
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_waypoint_reached_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN];
    _mav_put_uint16_t(buf, 0, seq);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN);
#else
    mavlink_task_mission_waypoint_reached_t packet;
    packet.seq = seq;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_CRC);
}

/**
 * @brief Encode a task_mission_waypoint_reached struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_waypoint_reached C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_waypoint_reached_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_task_mission_waypoint_reached_t* task_mission_waypoint_reached)
{
    return mavlink_msg_task_mission_waypoint_reached_pack(system_id, component_id, msg, task_mission_waypoint_reached->seq);
}

/**
 * @brief Encode a task_mission_waypoint_reached struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_waypoint_reached C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_waypoint_reached_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_task_mission_waypoint_reached_t* task_mission_waypoint_reached)
{
    return mavlink_msg_task_mission_waypoint_reached_pack_chan(system_id, component_id, chan, msg, task_mission_waypoint_reached->seq);
}

/**
 * @brief Send a task_mission_waypoint_reached message
 * @param chan MAVLink channel to send the message
 *
 * @param seq  task mission index
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_mission_waypoint_reached_send(mavlink_channel_t chan, uint16_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN];
    _mav_put_uint16_t(buf, 0, seq);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED, buf, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_CRC);
#else
    mavlink_task_mission_waypoint_reached_t packet;
    packet.seq = seq;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED, (const char *)&packet, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_CRC);
#endif
}

/**
 * @brief Send a task_mission_waypoint_reached message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_task_mission_waypoint_reached_send_struct(mavlink_channel_t chan, const mavlink_task_mission_waypoint_reached_t* task_mission_waypoint_reached)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_task_mission_waypoint_reached_send(chan, task_mission_waypoint_reached->seq);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED, (const char *)task_mission_waypoint_reached, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_mission_waypoint_reached_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, seq);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED, buf, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_CRC);
#else
    mavlink_task_mission_waypoint_reached_t *packet = (mavlink_task_mission_waypoint_reached_t *)msgbuf;
    packet->seq = seq;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED, (const char *)packet, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_MISSION_WAYPOINT_REACHED UNPACKING


/**
 * @brief Get field seq from task_mission_waypoint_reached message
 *
 * @return  task mission index
 */
static inline uint16_t mavlink_msg_task_mission_waypoint_reached_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a task_mission_waypoint_reached message into a struct
 *
 * @param msg The message to decode
 * @param task_mission_waypoint_reached C-struct to decode the message contents into
 */
static inline void mavlink_msg_task_mission_waypoint_reached_decode(const mavlink_message_t* msg, mavlink_task_mission_waypoint_reached_t* task_mission_waypoint_reached)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    task_mission_waypoint_reached->seq = mavlink_msg_task_mission_waypoint_reached_get_seq(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN? msg->len : MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN;
        memset(task_mission_waypoint_reached, 0, MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_LEN);
    memcpy(task_mission_waypoint_reached, _MAV_PAYLOAD(msg), len);
#endif
}
