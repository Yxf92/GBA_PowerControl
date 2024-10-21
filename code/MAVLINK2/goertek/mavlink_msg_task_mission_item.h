#pragma once
// MESSAGE TASK_MISSION_ITEM PACKING

#define MAVLINK_MSG_ID_TASK_MISSION_ITEM 4011


typedef struct __mavlink_task_mission_item_t {
 float lat; /*<  waypoint latitude.*/
 float lon; /*<  waypoint longitude.*/
 float alt; /*<  waypoint altitude.*/
 float gb_pitch; /*<  gimbal pitch value -1f..1f.*/
 float gb_yaw; /*<  gimbal yaw angle, the uint is radian, the range is -PI ~ PI.*/
 float uav_yaw; /*<  vehicle global yaw.*/
 float action; /*<  vehicle and camera execution. see enum(TASK_ACTION).*/
 float velocity; /*<  flight velocity, unit is meters.*/
 float param1; /*<  Reserved */
 float param2; /*<  Reserved */
 float param3; /*<  Reserved */
 float param4; /*<  Reserved */
 int16_t index; /*<  waypoint sequence.*/
 int16_t count; /*<  waypoint count.*/
 int16_t type; /*<  waypoint type, see enum(TASK_MISSION_TYPE).*/
 int8_t frame; /*<  The coordinate system of the waypoint, see enum MAV_FRAME*/
} mavlink_task_mission_item_t;

#define MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN 55
#define MAVLINK_MSG_ID_TASK_MISSION_ITEM_MIN_LEN 55
#define MAVLINK_MSG_ID_4011_LEN 55
#define MAVLINK_MSG_ID_4011_MIN_LEN 55

#define MAVLINK_MSG_ID_TASK_MISSION_ITEM_CRC 110
#define MAVLINK_MSG_ID_4011_CRC 110



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_ITEM { \
    4011, \
    "TASK_MISSION_ITEM", \
    16, \
    {  { "index", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_task_mission_item_t, index) }, \
         { "count", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_task_mission_item_t, count) }, \
         { "type", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_task_mission_item_t, type) }, \
         { "frame", NULL, MAVLINK_TYPE_INT8_T, 0, 54, offsetof(mavlink_task_mission_item_t, frame) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_task_mission_item_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_mission_item_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_mission_item_t, alt) }, \
         { "gb_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_task_mission_item_t, gb_pitch) }, \
         { "gb_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_task_mission_item_t, gb_yaw) }, \
         { "uav_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_task_mission_item_t, uav_yaw) }, \
         { "action", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_task_mission_item_t, action) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_task_mission_item_t, velocity) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_task_mission_item_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_task_mission_item_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_task_mission_item_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_task_mission_item_t, param4) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_ITEM { \
    "TASK_MISSION_ITEM", \
    16, \
    {  { "index", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_task_mission_item_t, index) }, \
         { "count", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_task_mission_item_t, count) }, \
         { "type", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_task_mission_item_t, type) }, \
         { "frame", NULL, MAVLINK_TYPE_INT8_T, 0, 54, offsetof(mavlink_task_mission_item_t, frame) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_task_mission_item_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_mission_item_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_mission_item_t, alt) }, \
         { "gb_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_task_mission_item_t, gb_pitch) }, \
         { "gb_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_task_mission_item_t, gb_yaw) }, \
         { "uav_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_task_mission_item_t, uav_yaw) }, \
         { "action", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_task_mission_item_t, action) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_task_mission_item_t, velocity) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_task_mission_item_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_task_mission_item_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_task_mission_item_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_task_mission_item_t, param4) }, \
         } \
}
#endif

/**
 * @brief Pack a task_mission_item message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  waypoint sequence.
 * @param count  waypoint count.
 * @param type  waypoint type, see enum(TASK_MISSION_TYPE).
 * @param frame  The coordinate system of the waypoint, see enum MAV_FRAME
 * @param lat  waypoint latitude.
 * @param lon  waypoint longitude.
 * @param alt  waypoint altitude.
 * @param gb_pitch  gimbal pitch value -1f..1f.
 * @param gb_yaw  gimbal yaw angle, the uint is radian, the range is -PI ~ PI.
 * @param uav_yaw  vehicle global yaw.
 * @param action  vehicle and camera execution. see enum(TASK_ACTION).
 * @param velocity  flight velocity, unit is meters.
 * @param param1  Reserved 
 * @param param2  Reserved 
 * @param param3  Reserved 
 * @param param4  Reserved 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_item_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t index, int16_t count, int16_t type, int8_t frame, float lat, float lon, float alt, float gb_pitch, float gb_yaw, float uav_yaw, float action, float velocity, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_float(buf, 8, alt);
    _mav_put_float(buf, 12, gb_pitch);
    _mav_put_float(buf, 16, gb_yaw);
    _mav_put_float(buf, 20, uav_yaw);
    _mav_put_float(buf, 24, action);
    _mav_put_float(buf, 28, velocity);
    _mav_put_float(buf, 32, param1);
    _mav_put_float(buf, 36, param2);
    _mav_put_float(buf, 40, param3);
    _mav_put_float(buf, 44, param4);
    _mav_put_int16_t(buf, 48, index);
    _mav_put_int16_t(buf, 50, count);
    _mav_put_int16_t(buf, 52, type);
    _mav_put_int8_t(buf, 54, frame);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN);
#else
    mavlink_task_mission_item_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.gb_pitch = gb_pitch;
    packet.gb_yaw = gb_yaw;
    packet.uav_yaw = uav_yaw;
    packet.action = action;
    packet.velocity = velocity;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.index = index;
    packet.count = count;
    packet.type = type;
    packet.frame = frame;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_ITEM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TASK_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_CRC);
}

/**
 * @brief Pack a task_mission_item message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  waypoint sequence.
 * @param count  waypoint count.
 * @param type  waypoint type, see enum(TASK_MISSION_TYPE).
 * @param frame  The coordinate system of the waypoint, see enum MAV_FRAME
 * @param lat  waypoint latitude.
 * @param lon  waypoint longitude.
 * @param alt  waypoint altitude.
 * @param gb_pitch  gimbal pitch value -1f..1f.
 * @param gb_yaw  gimbal yaw angle, the uint is radian, the range is -PI ~ PI.
 * @param uav_yaw  vehicle global yaw.
 * @param action  vehicle and camera execution. see enum(TASK_ACTION).
 * @param velocity  flight velocity, unit is meters.
 * @param param1  Reserved 
 * @param param2  Reserved 
 * @param param3  Reserved 
 * @param param4  Reserved 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_item_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t index,int16_t count,int16_t type,int8_t frame,float lat,float lon,float alt,float gb_pitch,float gb_yaw,float uav_yaw,float action,float velocity,float param1,float param2,float param3,float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_float(buf, 8, alt);
    _mav_put_float(buf, 12, gb_pitch);
    _mav_put_float(buf, 16, gb_yaw);
    _mav_put_float(buf, 20, uav_yaw);
    _mav_put_float(buf, 24, action);
    _mav_put_float(buf, 28, velocity);
    _mav_put_float(buf, 32, param1);
    _mav_put_float(buf, 36, param2);
    _mav_put_float(buf, 40, param3);
    _mav_put_float(buf, 44, param4);
    _mav_put_int16_t(buf, 48, index);
    _mav_put_int16_t(buf, 50, count);
    _mav_put_int16_t(buf, 52, type);
    _mav_put_int8_t(buf, 54, frame);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN);
#else
    mavlink_task_mission_item_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.gb_pitch = gb_pitch;
    packet.gb_yaw = gb_yaw;
    packet.uav_yaw = uav_yaw;
    packet.action = action;
    packet.velocity = velocity;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.index = index;
    packet.count = count;
    packet.type = type;
    packet.frame = frame;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_ITEM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TASK_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_CRC);
}

/**
 * @brief Encode a task_mission_item struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_item C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_item_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_task_mission_item_t* task_mission_item)
{
    return mavlink_msg_task_mission_item_pack(system_id, component_id, msg, task_mission_item->index, task_mission_item->count, task_mission_item->type, task_mission_item->frame, task_mission_item->lat, task_mission_item->lon, task_mission_item->alt, task_mission_item->gb_pitch, task_mission_item->gb_yaw, task_mission_item->uav_yaw, task_mission_item->action, task_mission_item->velocity, task_mission_item->param1, task_mission_item->param2, task_mission_item->param3, task_mission_item->param4);
}

/**
 * @brief Encode a task_mission_item struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_item C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_item_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_task_mission_item_t* task_mission_item)
{
    return mavlink_msg_task_mission_item_pack_chan(system_id, component_id, chan, msg, task_mission_item->index, task_mission_item->count, task_mission_item->type, task_mission_item->frame, task_mission_item->lat, task_mission_item->lon, task_mission_item->alt, task_mission_item->gb_pitch, task_mission_item->gb_yaw, task_mission_item->uav_yaw, task_mission_item->action, task_mission_item->velocity, task_mission_item->param1, task_mission_item->param2, task_mission_item->param3, task_mission_item->param4);
}

/**
 * @brief Send a task_mission_item message
 * @param chan MAVLink channel to send the message
 *
 * @param index  waypoint sequence.
 * @param count  waypoint count.
 * @param type  waypoint type, see enum(TASK_MISSION_TYPE).
 * @param frame  The coordinate system of the waypoint, see enum MAV_FRAME
 * @param lat  waypoint latitude.
 * @param lon  waypoint longitude.
 * @param alt  waypoint altitude.
 * @param gb_pitch  gimbal pitch value -1f..1f.
 * @param gb_yaw  gimbal yaw angle, the uint is radian, the range is -PI ~ PI.
 * @param uav_yaw  vehicle global yaw.
 * @param action  vehicle and camera execution. see enum(TASK_ACTION).
 * @param velocity  flight velocity, unit is meters.
 * @param param1  Reserved 
 * @param param2  Reserved 
 * @param param3  Reserved 
 * @param param4  Reserved 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_mission_item_send(mavlink_channel_t chan, int16_t index, int16_t count, int16_t type, int8_t frame, float lat, float lon, float alt, float gb_pitch, float gb_yaw, float uav_yaw, float action, float velocity, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_float(buf, 8, alt);
    _mav_put_float(buf, 12, gb_pitch);
    _mav_put_float(buf, 16, gb_yaw);
    _mav_put_float(buf, 20, uav_yaw);
    _mav_put_float(buf, 24, action);
    _mav_put_float(buf, 28, velocity);
    _mav_put_float(buf, 32, param1);
    _mav_put_float(buf, 36, param2);
    _mav_put_float(buf, 40, param3);
    _mav_put_float(buf, 44, param4);
    _mav_put_int16_t(buf, 48, index);
    _mav_put_int16_t(buf, 50, count);
    _mav_put_int16_t(buf, 52, type);
    _mav_put_int8_t(buf, 54, frame);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_ITEM, buf, MAVLINK_MSG_ID_TASK_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_CRC);
#else
    mavlink_task_mission_item_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.gb_pitch = gb_pitch;
    packet.gb_yaw = gb_yaw;
    packet.uav_yaw = uav_yaw;
    packet.action = action;
    packet.velocity = velocity;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.index = index;
    packet.count = count;
    packet.type = type;
    packet.frame = frame;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_ITEM, (const char *)&packet, MAVLINK_MSG_ID_TASK_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_CRC);
#endif
}

/**
 * @brief Send a task_mission_item message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_task_mission_item_send_struct(mavlink_channel_t chan, const mavlink_task_mission_item_t* task_mission_item)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_task_mission_item_send(chan, task_mission_item->index, task_mission_item->count, task_mission_item->type, task_mission_item->frame, task_mission_item->lat, task_mission_item->lon, task_mission_item->alt, task_mission_item->gb_pitch, task_mission_item->gb_yaw, task_mission_item->uav_yaw, task_mission_item->action, task_mission_item->velocity, task_mission_item->param1, task_mission_item->param2, task_mission_item->param3, task_mission_item->param4);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_ITEM, (const char *)task_mission_item, MAVLINK_MSG_ID_TASK_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_mission_item_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t index, int16_t count, int16_t type, int8_t frame, float lat, float lon, float alt, float gb_pitch, float gb_yaw, float uav_yaw, float action, float velocity, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_float(buf, 8, alt);
    _mav_put_float(buf, 12, gb_pitch);
    _mav_put_float(buf, 16, gb_yaw);
    _mav_put_float(buf, 20, uav_yaw);
    _mav_put_float(buf, 24, action);
    _mav_put_float(buf, 28, velocity);
    _mav_put_float(buf, 32, param1);
    _mav_put_float(buf, 36, param2);
    _mav_put_float(buf, 40, param3);
    _mav_put_float(buf, 44, param4);
    _mav_put_int16_t(buf, 48, index);
    _mav_put_int16_t(buf, 50, count);
    _mav_put_int16_t(buf, 52, type);
    _mav_put_int8_t(buf, 54, frame);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_ITEM, buf, MAVLINK_MSG_ID_TASK_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_CRC);
#else
    mavlink_task_mission_item_t *packet = (mavlink_task_mission_item_t *)msgbuf;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;
    packet->gb_pitch = gb_pitch;
    packet->gb_yaw = gb_yaw;
    packet->uav_yaw = uav_yaw;
    packet->action = action;
    packet->velocity = velocity;
    packet->param1 = param1;
    packet->param2 = param2;
    packet->param3 = param3;
    packet->param4 = param4;
    packet->index = index;
    packet->count = count;
    packet->type = type;
    packet->frame = frame;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_ITEM, (const char *)packet, MAVLINK_MSG_ID_TASK_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN, MAVLINK_MSG_ID_TASK_MISSION_ITEM_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_MISSION_ITEM UNPACKING


/**
 * @brief Get field index from task_mission_item message
 *
 * @return  waypoint sequence.
 */
static inline int16_t mavlink_msg_task_mission_item_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  48);
}

/**
 * @brief Get field count from task_mission_item message
 *
 * @return  waypoint count.
 */
static inline int16_t mavlink_msg_task_mission_item_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  50);
}

/**
 * @brief Get field type from task_mission_item message
 *
 * @return  waypoint type, see enum(TASK_MISSION_TYPE).
 */
static inline int16_t mavlink_msg_task_mission_item_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  52);
}

/**
 * @brief Get field frame from task_mission_item message
 *
 * @return  The coordinate system of the waypoint, see enum MAV_FRAME
 */
static inline int8_t mavlink_msg_task_mission_item_get_frame(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  54);
}

/**
 * @brief Get field lat from task_mission_item message
 *
 * @return  waypoint latitude.
 */
static inline float mavlink_msg_task_mission_item_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field lon from task_mission_item message
 *
 * @return  waypoint longitude.
 */
static inline float mavlink_msg_task_mission_item_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field alt from task_mission_item message
 *
 * @return  waypoint altitude.
 */
static inline float mavlink_msg_task_mission_item_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field gb_pitch from task_mission_item message
 *
 * @return  gimbal pitch value -1f..1f.
 */
static inline float mavlink_msg_task_mission_item_get_gb_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field gb_yaw from task_mission_item message
 *
 * @return  gimbal yaw angle, the uint is radian, the range is -PI ~ PI.
 */
static inline float mavlink_msg_task_mission_item_get_gb_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field uav_yaw from task_mission_item message
 *
 * @return  vehicle global yaw.
 */
static inline float mavlink_msg_task_mission_item_get_uav_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field action from task_mission_item message
 *
 * @return  vehicle and camera execution. see enum(TASK_ACTION).
 */
static inline float mavlink_msg_task_mission_item_get_action(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field velocity from task_mission_item message
 *
 * @return  flight velocity, unit is meters.
 */
static inline float mavlink_msg_task_mission_item_get_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field param1 from task_mission_item message
 *
 * @return  Reserved 
 */
static inline float mavlink_msg_task_mission_item_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field param2 from task_mission_item message
 *
 * @return  Reserved 
 */
static inline float mavlink_msg_task_mission_item_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field param3 from task_mission_item message
 *
 * @return  Reserved 
 */
static inline float mavlink_msg_task_mission_item_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field param4 from task_mission_item message
 *
 * @return  Reserved 
 */
static inline float mavlink_msg_task_mission_item_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Decode a task_mission_item message into a struct
 *
 * @param msg The message to decode
 * @param task_mission_item C-struct to decode the message contents into
 */
static inline void mavlink_msg_task_mission_item_decode(const mavlink_message_t* msg, mavlink_task_mission_item_t* task_mission_item)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    task_mission_item->lat = mavlink_msg_task_mission_item_get_lat(msg);
    task_mission_item->lon = mavlink_msg_task_mission_item_get_lon(msg);
    task_mission_item->alt = mavlink_msg_task_mission_item_get_alt(msg);
    task_mission_item->gb_pitch = mavlink_msg_task_mission_item_get_gb_pitch(msg);
    task_mission_item->gb_yaw = mavlink_msg_task_mission_item_get_gb_yaw(msg);
    task_mission_item->uav_yaw = mavlink_msg_task_mission_item_get_uav_yaw(msg);
    task_mission_item->action = mavlink_msg_task_mission_item_get_action(msg);
    task_mission_item->velocity = mavlink_msg_task_mission_item_get_velocity(msg);
    task_mission_item->param1 = mavlink_msg_task_mission_item_get_param1(msg);
    task_mission_item->param2 = mavlink_msg_task_mission_item_get_param2(msg);
    task_mission_item->param3 = mavlink_msg_task_mission_item_get_param3(msg);
    task_mission_item->param4 = mavlink_msg_task_mission_item_get_param4(msg);
    task_mission_item->index = mavlink_msg_task_mission_item_get_index(msg);
    task_mission_item->count = mavlink_msg_task_mission_item_get_count(msg);
    task_mission_item->type = mavlink_msg_task_mission_item_get_type(msg);
    task_mission_item->frame = mavlink_msg_task_mission_item_get_frame(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN? msg->len : MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN;
        memset(task_mission_item, 0, MAVLINK_MSG_ID_TASK_MISSION_ITEM_LEN);
    memcpy(task_mission_item, _MAV_PAYLOAD(msg), len);
#endif
}
