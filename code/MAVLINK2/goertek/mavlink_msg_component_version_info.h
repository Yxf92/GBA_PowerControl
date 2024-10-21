#pragma once
// MESSAGE COMPONENT_VERSION_INFO PACKING

#define MAVLINK_MSG_ID_COMPONENT_VERSION_INFO 4029


typedef struct __mavlink_component_version_info_t {
 uint16_t software_version_build; /*<  software version build number*/
 uint16_t hardware_version; /*<  hardware version*/
 uint8_t software_version_major; /*<  software version major number*/
 uint8_t software_version_minor; /*<  software version minor number*/
} mavlink_component_version_info_t;

#define MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN 6
#define MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_MIN_LEN 6
#define MAVLINK_MSG_ID_4029_LEN 6
#define MAVLINK_MSG_ID_4029_MIN_LEN 6

#define MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_CRC 66
#define MAVLINK_MSG_ID_4029_CRC 66



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMPONENT_VERSION_INFO { \
    4029, \
    "COMPONENT_VERSION_INFO", \
    4, \
    {  { "software_version_major", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_component_version_info_t, software_version_major) }, \
         { "software_version_minor", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_component_version_info_t, software_version_minor) }, \
         { "software_version_build", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_component_version_info_t, software_version_build) }, \
         { "hardware_version", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_component_version_info_t, hardware_version) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMPONENT_VERSION_INFO { \
    "COMPONENT_VERSION_INFO", \
    4, \
    {  { "software_version_major", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_component_version_info_t, software_version_major) }, \
         { "software_version_minor", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_component_version_info_t, software_version_minor) }, \
         { "software_version_build", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_component_version_info_t, software_version_build) }, \
         { "hardware_version", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_component_version_info_t, hardware_version) }, \
         } \
}
#endif

/**
 * @brief Pack a component_version_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param software_version_major  software version major number
 * @param software_version_minor  software version minor number
 * @param software_version_build  software version build number
 * @param hardware_version  hardware version
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_component_version_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t software_version_major, uint8_t software_version_minor, uint16_t software_version_build, uint16_t hardware_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN];
    _mav_put_uint16_t(buf, 0, software_version_build);
    _mav_put_uint16_t(buf, 2, hardware_version);
    _mav_put_uint8_t(buf, 4, software_version_major);
    _mav_put_uint8_t(buf, 5, software_version_minor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN);
#else
    mavlink_component_version_info_t packet;
    packet.software_version_build = software_version_build;
    packet.hardware_version = hardware_version;
    packet.software_version_major = software_version_major;
    packet.software_version_minor = software_version_minor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMPONENT_VERSION_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_CRC);
}

/**
 * @brief Pack a component_version_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param software_version_major  software version major number
 * @param software_version_minor  software version minor number
 * @param software_version_build  software version build number
 * @param hardware_version  hardware version
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_component_version_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t software_version_major,uint8_t software_version_minor,uint16_t software_version_build,uint16_t hardware_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN];
    _mav_put_uint16_t(buf, 0, software_version_build);
    _mav_put_uint16_t(buf, 2, hardware_version);
    _mav_put_uint8_t(buf, 4, software_version_major);
    _mav_put_uint8_t(buf, 5, software_version_minor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN);
#else
    mavlink_component_version_info_t packet;
    packet.software_version_build = software_version_build;
    packet.hardware_version = hardware_version;
    packet.software_version_major = software_version_major;
    packet.software_version_minor = software_version_minor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMPONENT_VERSION_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_CRC);
}

/**
 * @brief Encode a component_version_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param component_version_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_component_version_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_component_version_info_t* component_version_info)
{
    return mavlink_msg_component_version_info_pack(system_id, component_id, msg, component_version_info->software_version_major, component_version_info->software_version_minor, component_version_info->software_version_build, component_version_info->hardware_version);
}

/**
 * @brief Encode a component_version_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param component_version_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_component_version_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_component_version_info_t* component_version_info)
{
    return mavlink_msg_component_version_info_pack_chan(system_id, component_id, chan, msg, component_version_info->software_version_major, component_version_info->software_version_minor, component_version_info->software_version_build, component_version_info->hardware_version);
}

/**
 * @brief Send a component_version_info message
 * @param chan MAVLink channel to send the message
 *
 * @param software_version_major  software version major number
 * @param software_version_minor  software version minor number
 * @param software_version_build  software version build number
 * @param hardware_version  hardware version
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_component_version_info_send(mavlink_channel_t chan, uint8_t software_version_major, uint8_t software_version_minor, uint16_t software_version_build, uint16_t hardware_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN];
    _mav_put_uint16_t(buf, 0, software_version_build);
    _mav_put_uint16_t(buf, 2, hardware_version);
    _mav_put_uint8_t(buf, 4, software_version_major);
    _mav_put_uint8_t(buf, 5, software_version_minor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO, buf, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_CRC);
#else
    mavlink_component_version_info_t packet;
    packet.software_version_build = software_version_build;
    packet.hardware_version = hardware_version;
    packet.software_version_major = software_version_major;
    packet.software_version_minor = software_version_minor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO, (const char *)&packet, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_CRC);
#endif
}

/**
 * @brief Send a component_version_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_component_version_info_send_struct(mavlink_channel_t chan, const mavlink_component_version_info_t* component_version_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_component_version_info_send(chan, component_version_info->software_version_major, component_version_info->software_version_minor, component_version_info->software_version_build, component_version_info->hardware_version);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO, (const char *)component_version_info, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_component_version_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t software_version_major, uint8_t software_version_minor, uint16_t software_version_build, uint16_t hardware_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, software_version_build);
    _mav_put_uint16_t(buf, 2, hardware_version);
    _mav_put_uint8_t(buf, 4, software_version_major);
    _mav_put_uint8_t(buf, 5, software_version_minor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO, buf, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_CRC);
#else
    mavlink_component_version_info_t *packet = (mavlink_component_version_info_t *)msgbuf;
    packet->software_version_build = software_version_build;
    packet->hardware_version = hardware_version;
    packet->software_version_major = software_version_major;
    packet->software_version_minor = software_version_minor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO, (const char *)packet, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE COMPONENT_VERSION_INFO UNPACKING


/**
 * @brief Get field software_version_major from component_version_info message
 *
 * @return  software version major number
 */
static inline uint8_t mavlink_msg_component_version_info_get_software_version_major(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field software_version_minor from component_version_info message
 *
 * @return  software version minor number
 */
static inline uint8_t mavlink_msg_component_version_info_get_software_version_minor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field software_version_build from component_version_info message
 *
 * @return  software version build number
 */
static inline uint16_t mavlink_msg_component_version_info_get_software_version_build(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field hardware_version from component_version_info message
 *
 * @return  hardware version
 */
static inline uint16_t mavlink_msg_component_version_info_get_hardware_version(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Decode a component_version_info message into a struct
 *
 * @param msg The message to decode
 * @param component_version_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_component_version_info_decode(const mavlink_message_t* msg, mavlink_component_version_info_t* component_version_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    component_version_info->software_version_build = mavlink_msg_component_version_info_get_software_version_build(msg);
    component_version_info->hardware_version = mavlink_msg_component_version_info_get_hardware_version(msg);
    component_version_info->software_version_major = mavlink_msg_component_version_info_get_software_version_major(msg);
    component_version_info->software_version_minor = mavlink_msg_component_version_info_get_software_version_minor(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN? msg->len : MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN;
        memset(component_version_info, 0, MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_LEN);
    memcpy(component_version_info, _MAV_PAYLOAD(msg), len);
#endif
}
