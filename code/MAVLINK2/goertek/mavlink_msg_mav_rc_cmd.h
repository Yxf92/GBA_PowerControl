#pragma once
// MESSAGE MAV_RC_CMD PACKING

#define MAVLINK_MSG_ID_MAV_RC_CMD 7050


typedef struct __mavlink_mav_rc_cmd_t {
 uint8_t command; /*<  */
 uint8_t params[254]; /*<  */
} mavlink_mav_rc_cmd_t;

#define MAVLINK_MSG_ID_MAV_RC_CMD_LEN 255
#define MAVLINK_MSG_ID_MAV_RC_CMD_MIN_LEN 255
#define MAVLINK_MSG_ID_7050_LEN 255
#define MAVLINK_MSG_ID_7050_MIN_LEN 255

#define MAVLINK_MSG_ID_MAV_RC_CMD_CRC 251
#define MAVLINK_MSG_ID_7050_CRC 251

#define MAVLINK_MSG_MAV_RC_CMD_FIELD_PARAMS_LEN 254

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MAV_RC_CMD { \
    7050, \
    "MAV_RC_CMD", \
    2, \
    {  { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mav_rc_cmd_t, command) }, \
         { "params", NULL, MAVLINK_TYPE_UINT8_T, 254, 1, offsetof(mavlink_mav_rc_cmd_t, params) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MAV_RC_CMD { \
    "MAV_RC_CMD", \
    2, \
    {  { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mav_rc_cmd_t, command) }, \
         { "params", NULL, MAVLINK_TYPE_UINT8_T, 254, 1, offsetof(mavlink_mav_rc_cmd_t, params) }, \
         } \
}
#endif

/**
 * @brief Pack a mav_rc_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param command  
 * @param params  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mav_rc_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t command, const uint8_t *params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAV_RC_CMD_LEN];
    _mav_put_uint8_t(buf, 0, command);
    _mav_put_uint8_t_array(buf, 1, params, 254);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MAV_RC_CMD_LEN);
#else
    mavlink_mav_rc_cmd_t packet;
    packet.command = command;
    mav_array_memcpy(packet.params, params, sizeof(uint8_t)*254);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MAV_RC_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MAV_RC_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MAV_RC_CMD_MIN_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_CRC);
}

/**
 * @brief Pack a mav_rc_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command  
 * @param params  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mav_rc_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t command,const uint8_t *params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAV_RC_CMD_LEN];
    _mav_put_uint8_t(buf, 0, command);
    _mav_put_uint8_t_array(buf, 1, params, 254);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MAV_RC_CMD_LEN);
#else
    mavlink_mav_rc_cmd_t packet;
    packet.command = command;
    mav_array_memcpy(packet.params, params, sizeof(uint8_t)*254);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MAV_RC_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MAV_RC_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MAV_RC_CMD_MIN_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_CRC);
}

/**
 * @brief Encode a mav_rc_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mav_rc_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mav_rc_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mav_rc_cmd_t* mav_rc_cmd)
{
    return mavlink_msg_mav_rc_cmd_pack(system_id, component_id, msg, mav_rc_cmd->command, mav_rc_cmd->params);
}

/**
 * @brief Encode a mav_rc_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mav_rc_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mav_rc_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mav_rc_cmd_t* mav_rc_cmd)
{
    return mavlink_msg_mav_rc_cmd_pack_chan(system_id, component_id, chan, msg, mav_rc_cmd->command, mav_rc_cmd->params);
}

/**
 * @brief Send a mav_rc_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param command  
 * @param params  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mav_rc_cmd_send(mavlink_channel_t chan, uint8_t command, const uint8_t *params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAV_RC_CMD_LEN];
    _mav_put_uint8_t(buf, 0, command);
    _mav_put_uint8_t_array(buf, 1, params, 254);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAV_RC_CMD, buf, MAVLINK_MSG_ID_MAV_RC_CMD_MIN_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_CRC);
#else
    mavlink_mav_rc_cmd_t packet;
    packet.command = command;
    mav_array_memcpy(packet.params, params, sizeof(uint8_t)*254);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAV_RC_CMD, (const char *)&packet, MAVLINK_MSG_ID_MAV_RC_CMD_MIN_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_CRC);
#endif
}

/**
 * @brief Send a mav_rc_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mav_rc_cmd_send_struct(mavlink_channel_t chan, const mavlink_mav_rc_cmd_t* mav_rc_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mav_rc_cmd_send(chan, mav_rc_cmd->command, mav_rc_cmd->params);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAV_RC_CMD, (const char *)mav_rc_cmd, MAVLINK_MSG_ID_MAV_RC_CMD_MIN_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_MAV_RC_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mav_rc_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t command, const uint8_t *params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, command);
    _mav_put_uint8_t_array(buf, 1, params, 254);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAV_RC_CMD, buf, MAVLINK_MSG_ID_MAV_RC_CMD_MIN_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_CRC);
#else
    mavlink_mav_rc_cmd_t *packet = (mavlink_mav_rc_cmd_t *)msgbuf;
    packet->command = command;
    mav_array_memcpy(packet->params, params, sizeof(uint8_t)*254);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAV_RC_CMD, (const char *)packet, MAVLINK_MSG_ID_MAV_RC_CMD_MIN_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_LEN, MAVLINK_MSG_ID_MAV_RC_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE MAV_RC_CMD UNPACKING


/**
 * @brief Get field command from mav_rc_cmd message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_mav_rc_cmd_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field params from mav_rc_cmd message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_mav_rc_cmd_get_params(const mavlink_message_t* msg, uint8_t *params)
{
    return _MAV_RETURN_uint8_t_array(msg, params, 254,  1);
}

/**
 * @brief Decode a mav_rc_cmd message into a struct
 *
 * @param msg The message to decode
 * @param mav_rc_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_mav_rc_cmd_decode(const mavlink_message_t* msg, mavlink_mav_rc_cmd_t* mav_rc_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mav_rc_cmd->command = mavlink_msg_mav_rc_cmd_get_command(msg);
    mavlink_msg_mav_rc_cmd_get_params(msg, mav_rc_cmd->params);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MAV_RC_CMD_LEN? msg->len : MAVLINK_MSG_ID_MAV_RC_CMD_LEN;
        memset(mav_rc_cmd, 0, MAVLINK_MSG_ID_MAV_RC_CMD_LEN);
    memcpy(mav_rc_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
