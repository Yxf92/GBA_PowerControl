#pragma once
// MESSAGE MISSION_ACTION_ACK PACKING

#define MAVLINK_MSG_ID_MISSION_ACTION_ACK 4028


typedef struct __mavlink_mission_action_ack_t {
 uint8_t result; /*<  Result of action*/
 char mission_folder[10]; /*<  Folder name to store photo (valid only result is MAV_RESULT_ACCEPTED).*/
} mavlink_mission_action_ack_t;

#define MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN 11
#define MAVLINK_MSG_ID_MISSION_ACTION_ACK_MIN_LEN 11
#define MAVLINK_MSG_ID_4028_LEN 11
#define MAVLINK_MSG_ID_4028_MIN_LEN 11

#define MAVLINK_MSG_ID_MISSION_ACTION_ACK_CRC 44
#define MAVLINK_MSG_ID_4028_CRC 44

#define MAVLINK_MSG_MISSION_ACTION_ACK_FIELD_MISSION_FOLDER_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_ACTION_ACK { \
    4028, \
    "MISSION_ACTION_ACK", \
    2, \
    {  { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mission_action_ack_t, result) }, \
         { "mission_folder", NULL, MAVLINK_TYPE_CHAR, 10, 1, offsetof(mavlink_mission_action_ack_t, mission_folder) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_ACTION_ACK { \
    "MISSION_ACTION_ACK", \
    2, \
    {  { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mission_action_ack_t, result) }, \
         { "mission_folder", NULL, MAVLINK_TYPE_CHAR, 10, 1, offsetof(mavlink_mission_action_ack_t, mission_folder) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_action_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param result  Result of action
 * @param mission_folder  Folder name to store photo (valid only result is MAV_RESULT_ACCEPTED).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_action_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t result, const char *mission_folder)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN];
    _mav_put_uint8_t(buf, 0, result);
    _mav_put_char_array(buf, 1, mission_folder, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN);
#else
    mavlink_mission_action_ack_t packet;
    packet.result = result;
    mav_array_memcpy(packet.mission_folder, mission_folder, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_ACTION_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_ACTION_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_CRC);
}

/**
 * @brief Pack a mission_action_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param result  Result of action
 * @param mission_folder  Folder name to store photo (valid only result is MAV_RESULT_ACCEPTED).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_action_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t result,const char *mission_folder)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN];
    _mav_put_uint8_t(buf, 0, result);
    _mav_put_char_array(buf, 1, mission_folder, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN);
#else
    mavlink_mission_action_ack_t packet;
    packet.result = result;
    mav_array_memcpy(packet.mission_folder, mission_folder, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_ACTION_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_ACTION_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_CRC);
}

/**
 * @brief Encode a mission_action_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_action_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_action_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_action_ack_t* mission_action_ack)
{
    return mavlink_msg_mission_action_ack_pack(system_id, component_id, msg, mission_action_ack->result, mission_action_ack->mission_folder);
}

/**
 * @brief Encode a mission_action_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_action_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_action_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mission_action_ack_t* mission_action_ack)
{
    return mavlink_msg_mission_action_ack_pack_chan(system_id, component_id, chan, msg, mission_action_ack->result, mission_action_ack->mission_folder);
}

/**
 * @brief Send a mission_action_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param result  Result of action
 * @param mission_folder  Folder name to store photo (valid only result is MAV_RESULT_ACCEPTED).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mission_action_ack_send(mavlink_channel_t chan, uint8_t result, const char *mission_folder)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN];
    _mav_put_uint8_t(buf, 0, result);
    _mav_put_char_array(buf, 1, mission_folder, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ACTION_ACK, buf, MAVLINK_MSG_ID_MISSION_ACTION_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_CRC);
#else
    mavlink_mission_action_ack_t packet;
    packet.result = result;
    mav_array_memcpy(packet.mission_folder, mission_folder, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ACTION_ACK, (const char *)&packet, MAVLINK_MSG_ID_MISSION_ACTION_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_CRC);
#endif
}

/**
 * @brief Send a mission_action_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mission_action_ack_send_struct(mavlink_channel_t chan, const mavlink_mission_action_ack_t* mission_action_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mission_action_ack_send(chan, mission_action_ack->result, mission_action_ack->mission_folder);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ACTION_ACK, (const char *)mission_action_ack, MAVLINK_MSG_ID_MISSION_ACTION_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mission_action_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t result, const char *mission_folder)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, result);
    _mav_put_char_array(buf, 1, mission_folder, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ACTION_ACK, buf, MAVLINK_MSG_ID_MISSION_ACTION_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_CRC);
#else
    mavlink_mission_action_ack_t *packet = (mavlink_mission_action_ack_t *)msgbuf;
    packet->result = result;
    mav_array_memcpy(packet->mission_folder, mission_folder, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ACTION_ACK, (const char *)packet, MAVLINK_MSG_ID_MISSION_ACTION_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN, MAVLINK_MSG_ID_MISSION_ACTION_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE MISSION_ACTION_ACK UNPACKING


/**
 * @brief Get field result from mission_action_ack message
 *
 * @return  Result of action
 */
static inline uint8_t mavlink_msg_mission_action_ack_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field mission_folder from mission_action_ack message
 *
 * @return  Folder name to store photo (valid only result is MAV_RESULT_ACCEPTED).
 */
static inline uint16_t mavlink_msg_mission_action_ack_get_mission_folder(const mavlink_message_t* msg, char *mission_folder)
{
    return _MAV_RETURN_char_array(msg, mission_folder, 10,  1);
}

/**
 * @brief Decode a mission_action_ack message into a struct
 *
 * @param msg The message to decode
 * @param mission_action_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_action_ack_decode(const mavlink_message_t* msg, mavlink_mission_action_ack_t* mission_action_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mission_action_ack->result = mavlink_msg_mission_action_ack_get_result(msg);
    mavlink_msg_mission_action_ack_get_mission_folder(msg, mission_action_ack->mission_folder);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN? msg->len : MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN;
        memset(mission_action_ack, 0, MAVLINK_MSG_ID_MISSION_ACTION_ACK_LEN);
    memcpy(mission_action_ack, _MAV_PAYLOAD(msg), len);
#endif
}
