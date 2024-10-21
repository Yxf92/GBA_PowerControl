#pragma once
// MESSAGE CAMERA_NOTIFICATION_PANORAMA PACKING

#define MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA 4026


typedef struct __mavlink_camera_notification_panorama_t {
 uint16_t number; /*<  Total number of the photos taken successfully in one group.*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t result; /*<  0: Failed; 1: The Nth photo was taken successfully. 2: In progress.*/
 uint8_t index; /*<  The number of the photos in one group.*/
} mavlink_camera_notification_panorama_t;

#define MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN 6
#define MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_MIN_LEN 6
#define MAVLINK_MSG_ID_4026_LEN 6
#define MAVLINK_MSG_ID_4026_MIN_LEN 6

#define MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_CRC 210
#define MAVLINK_MSG_ID_4026_CRC 210



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CAMERA_NOTIFICATION_PANORAMA { \
    4026, \
    "CAMERA_NOTIFICATION_PANORAMA", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_camera_notification_panorama_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_camera_notification_panorama_t, target_component) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_camera_notification_panorama_t, result) }, \
         { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_camera_notification_panorama_t, index) }, \
         { "number", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_camera_notification_panorama_t, number) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CAMERA_NOTIFICATION_PANORAMA { \
    "CAMERA_NOTIFICATION_PANORAMA", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_camera_notification_panorama_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_camera_notification_panorama_t, target_component) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_camera_notification_panorama_t, result) }, \
         { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_camera_notification_panorama_t, index) }, \
         { "number", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_camera_notification_panorama_t, number) }, \
         } \
}
#endif

/**
 * @brief Pack a camera_notification_panorama message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param result  0: Failed; 1: The Nth photo was taken successfully. 2: In progress.
 * @param index  The number of the photos in one group.
 * @param number  Total number of the photos taken successfully in one group.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_camera_notification_panorama_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t result, uint8_t index, uint16_t number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN];
    _mav_put_uint16_t(buf, 0, number);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, result);
    _mav_put_uint8_t(buf, 5, index);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN);
#else
    mavlink_camera_notification_panorama_t packet;
    packet.number = number;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;
    packet.index = index;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_MIN_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_CRC);
}

/**
 * @brief Pack a camera_notification_panorama message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param result  0: Failed; 1: The Nth photo was taken successfully. 2: In progress.
 * @param index  The number of the photos in one group.
 * @param number  Total number of the photos taken successfully in one group.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_camera_notification_panorama_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t result,uint8_t index,uint16_t number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN];
    _mav_put_uint16_t(buf, 0, number);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, result);
    _mav_put_uint8_t(buf, 5, index);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN);
#else
    mavlink_camera_notification_panorama_t packet;
    packet.number = number;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;
    packet.index = index;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_MIN_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_CRC);
}

/**
 * @brief Encode a camera_notification_panorama struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param camera_notification_panorama C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_camera_notification_panorama_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_camera_notification_panorama_t* camera_notification_panorama)
{
    return mavlink_msg_camera_notification_panorama_pack(system_id, component_id, msg, camera_notification_panorama->target_system, camera_notification_panorama->target_component, camera_notification_panorama->result, camera_notification_panorama->index, camera_notification_panorama->number);
}

/**
 * @brief Encode a camera_notification_panorama struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param camera_notification_panorama C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_camera_notification_panorama_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_camera_notification_panorama_t* camera_notification_panorama)
{
    return mavlink_msg_camera_notification_panorama_pack_chan(system_id, component_id, chan, msg, camera_notification_panorama->target_system, camera_notification_panorama->target_component, camera_notification_panorama->result, camera_notification_panorama->index, camera_notification_panorama->number);
}

/**
 * @brief Send a camera_notification_panorama message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param result  0: Failed; 1: The Nth photo was taken successfully. 2: In progress.
 * @param index  The number of the photos in one group.
 * @param number  Total number of the photos taken successfully in one group.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_camera_notification_panorama_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t result, uint8_t index, uint16_t number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN];
    _mav_put_uint16_t(buf, 0, number);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, result);
    _mav_put_uint8_t(buf, 5, index);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA, buf, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_MIN_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_CRC);
#else
    mavlink_camera_notification_panorama_t packet;
    packet.number = number;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;
    packet.index = index;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA, (const char *)&packet, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_MIN_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_CRC);
#endif
}

/**
 * @brief Send a camera_notification_panorama message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_camera_notification_panorama_send_struct(mavlink_channel_t chan, const mavlink_camera_notification_panorama_t* camera_notification_panorama)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_camera_notification_panorama_send(chan, camera_notification_panorama->target_system, camera_notification_panorama->target_component, camera_notification_panorama->result, camera_notification_panorama->index, camera_notification_panorama->number);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA, (const char *)camera_notification_panorama, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_MIN_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_CRC);
#endif
}

#if MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_camera_notification_panorama_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t result, uint8_t index, uint16_t number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, number);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, result);
    _mav_put_uint8_t(buf, 5, index);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA, buf, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_MIN_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_CRC);
#else
    mavlink_camera_notification_panorama_t *packet = (mavlink_camera_notification_panorama_t *)msgbuf;
    packet->number = number;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->result = result;
    packet->index = index;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA, (const char *)packet, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_MIN_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_CRC);
#endif
}
#endif

#endif

// MESSAGE CAMERA_NOTIFICATION_PANORAMA UNPACKING


/**
 * @brief Get field target_system from camera_notification_panorama message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_camera_notification_panorama_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field target_component from camera_notification_panorama message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_camera_notification_panorama_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field result from camera_notification_panorama message
 *
 * @return  0: Failed; 1: The Nth photo was taken successfully. 2: In progress.
 */
static inline uint8_t mavlink_msg_camera_notification_panorama_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field index from camera_notification_panorama message
 *
 * @return  The number of the photos in one group.
 */
static inline uint8_t mavlink_msg_camera_notification_panorama_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field number from camera_notification_panorama message
 *
 * @return  Total number of the photos taken successfully in one group.
 */
static inline uint16_t mavlink_msg_camera_notification_panorama_get_number(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a camera_notification_panorama message into a struct
 *
 * @param msg The message to decode
 * @param camera_notification_panorama C-struct to decode the message contents into
 */
static inline void mavlink_msg_camera_notification_panorama_decode(const mavlink_message_t* msg, mavlink_camera_notification_panorama_t* camera_notification_panorama)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    camera_notification_panorama->number = mavlink_msg_camera_notification_panorama_get_number(msg);
    camera_notification_panorama->target_system = mavlink_msg_camera_notification_panorama_get_target_system(msg);
    camera_notification_panorama->target_component = mavlink_msg_camera_notification_panorama_get_target_component(msg);
    camera_notification_panorama->result = mavlink_msg_camera_notification_panorama_get_result(msg);
    camera_notification_panorama->index = mavlink_msg_camera_notification_panorama_get_index(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN? msg->len : MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN;
        memset(camera_notification_panorama, 0, MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_LEN);
    memcpy(camera_notification_panorama, _MAV_PAYLOAD(msg), len);
#endif
}
