#pragma once
// MESSAGE GOERTEK_BOOTLOAD_DATA PACKING

#define MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA 5003


typedef struct __mavlink_goertek_bootload_data_t {
 int8_t bootload_data[133]; /*<  gimbal bootload data.*/
} mavlink_goertek_bootload_data_t;

#define MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN 133
#define MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_MIN_LEN 133
#define MAVLINK_MSG_ID_5003_LEN 133
#define MAVLINK_MSG_ID_5003_MIN_LEN 133

#define MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_CRC 168
#define MAVLINK_MSG_ID_5003_CRC 168

#define MAVLINK_MSG_GOERTEK_BOOTLOAD_DATA_FIELD_BOOTLOAD_DATA_LEN 133

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GOERTEK_BOOTLOAD_DATA { \
    5003, \
    "GOERTEK_BOOTLOAD_DATA", \
    1, \
    {  { "bootload_data", NULL, MAVLINK_TYPE_INT8_T, 133, 0, offsetof(mavlink_goertek_bootload_data_t, bootload_data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GOERTEK_BOOTLOAD_DATA { \
    "GOERTEK_BOOTLOAD_DATA", \
    1, \
    {  { "bootload_data", NULL, MAVLINK_TYPE_INT8_T, 133, 0, offsetof(mavlink_goertek_bootload_data_t, bootload_data) }, \
         } \
}
#endif

/**
 * @brief Pack a goertek_bootload_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param bootload_data  gimbal bootload data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_goertek_bootload_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const int8_t *bootload_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN];

    _mav_put_int8_t_array(buf, 0, bootload_data, 133);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN);
#else
    mavlink_goertek_bootload_data_t packet;

    mav_array_memcpy(packet.bootload_data, bootload_data, sizeof(int8_t)*133);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_MIN_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_CRC);
}

/**
 * @brief Pack a goertek_bootload_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bootload_data  gimbal bootload data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_goertek_bootload_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const int8_t *bootload_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN];

    _mav_put_int8_t_array(buf, 0, bootload_data, 133);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN);
#else
    mavlink_goertek_bootload_data_t packet;

    mav_array_memcpy(packet.bootload_data, bootload_data, sizeof(int8_t)*133);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_MIN_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_CRC);
}

/**
 * @brief Encode a goertek_bootload_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param goertek_bootload_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_goertek_bootload_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_goertek_bootload_data_t* goertek_bootload_data)
{
    return mavlink_msg_goertek_bootload_data_pack(system_id, component_id, msg, goertek_bootload_data->bootload_data);
}

/**
 * @brief Encode a goertek_bootload_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param goertek_bootload_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_goertek_bootload_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_goertek_bootload_data_t* goertek_bootload_data)
{
    return mavlink_msg_goertek_bootload_data_pack_chan(system_id, component_id, chan, msg, goertek_bootload_data->bootload_data);
}

/**
 * @brief Send a goertek_bootload_data message
 * @param chan MAVLink channel to send the message
 *
 * @param bootload_data  gimbal bootload data.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_goertek_bootload_data_send(mavlink_channel_t chan, const int8_t *bootload_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN];

    _mav_put_int8_t_array(buf, 0, bootload_data, 133);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA, buf, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_MIN_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_CRC);
#else
    mavlink_goertek_bootload_data_t packet;

    mav_array_memcpy(packet.bootload_data, bootload_data, sizeof(int8_t)*133);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA, (const char *)&packet, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_MIN_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_CRC);
#endif
}

/**
 * @brief Send a goertek_bootload_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_goertek_bootload_data_send_struct(mavlink_channel_t chan, const mavlink_goertek_bootload_data_t* goertek_bootload_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_goertek_bootload_data_send(chan, goertek_bootload_data->bootload_data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA, (const char *)goertek_bootload_data, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_MIN_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_goertek_bootload_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const int8_t *bootload_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_int8_t_array(buf, 0, bootload_data, 133);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA, buf, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_MIN_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_CRC);
#else
    mavlink_goertek_bootload_data_t *packet = (mavlink_goertek_bootload_data_t *)msgbuf;

    mav_array_memcpy(packet->bootload_data, bootload_data, sizeof(int8_t)*133);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA, (const char *)packet, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_MIN_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE GOERTEK_BOOTLOAD_DATA UNPACKING


/**
 * @brief Get field bootload_data from goertek_bootload_data message
 *
 * @return  gimbal bootload data.
 */
static inline uint16_t mavlink_msg_goertek_bootload_data_get_bootload_data(const mavlink_message_t* msg, int8_t *bootload_data)
{
    return _MAV_RETURN_int8_t_array(msg, bootload_data, 133,  0);
}

/**
 * @brief Decode a goertek_bootload_data message into a struct
 *
 * @param msg The message to decode
 * @param goertek_bootload_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_goertek_bootload_data_decode(const mavlink_message_t* msg, mavlink_goertek_bootload_data_t* goertek_bootload_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_goertek_bootload_data_get_bootload_data(msg, goertek_bootload_data->bootload_data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN? msg->len : MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN;
        memset(goertek_bootload_data, 0, MAVLINK_MSG_ID_GOERTEK_BOOTLOAD_DATA_LEN);
    memcpy(goertek_bootload_data, _MAV_PAYLOAD(msg), len);
#endif
}
