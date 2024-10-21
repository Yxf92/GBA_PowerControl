#pragma once
// MESSAGE TASK_MISSION_DOWN_MIS PACKING

#define MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS 4012


typedef struct __mavlink_task_mission_down_mis_t {
 float lat; /*<  waypoint latitude*/
 float lon; /*<  waypoint longitude*/
 float alt; /*<  waypoint altitude*/
 float gb_pitch; /*<  gimbal pitch value -1f..1f*/
 float uav_yaw; /*<  vehicle global yaw*/
 float action; /*<  vehicle and camera execution. see enum(TASK_ACTION).*/
 float velocity; /*<  flight velocity, unit is meters.*/
 float param1; /*<  Reserved */
 float param2; /*<  Reserved */
 float param3; /*<  Reserved */
 float param4; /*<  Reserved */
 int16_t index; /*<  waypoint sequence*/
 int16_t count; /*<  waypoint count*/
 int16_t type; /*<  waypoint type, see enum(TASK_MISSION_TYPE).*/
} mavlink_task_mission_down_mis_t;

#define MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN 50
#define MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_MIN_LEN 50
#define MAVLINK_MSG_ID_4012_LEN 50
#define MAVLINK_MSG_ID_4012_MIN_LEN 50

#define MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_CRC 195
#define MAVLINK_MSG_ID_4012_CRC 195



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_DOWN_MIS { \
    4012, \
    "TASK_MISSION_DOWN_MIS", \
    14, \
    {  { "index", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_task_mission_down_mis_t, index) }, \
         { "count", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_task_mission_down_mis_t, count) }, \
         { "type", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_task_mission_down_mis_t, type) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_task_mission_down_mis_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_mission_down_mis_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_mission_down_mis_t, alt) }, \
         { "gb_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_task_mission_down_mis_t, gb_pitch) }, \
         { "uav_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_task_mission_down_mis_t, uav_yaw) }, \
         { "action", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_task_mission_down_mis_t, action) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_task_mission_down_mis_t, velocity) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_task_mission_down_mis_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_task_mission_down_mis_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_task_mission_down_mis_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_task_mission_down_mis_t, param4) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_MISSION_DOWN_MIS { \
    "TASK_MISSION_DOWN_MIS", \
    14, \
    {  { "index", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_task_mission_down_mis_t, index) }, \
         { "count", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_task_mission_down_mis_t, count) }, \
         { "type", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_task_mission_down_mis_t, type) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_task_mission_down_mis_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_mission_down_mis_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_mission_down_mis_t, alt) }, \
         { "gb_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_task_mission_down_mis_t, gb_pitch) }, \
         { "uav_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_task_mission_down_mis_t, uav_yaw) }, \
         { "action", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_task_mission_down_mis_t, action) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_task_mission_down_mis_t, velocity) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_task_mission_down_mis_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_task_mission_down_mis_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_task_mission_down_mis_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_task_mission_down_mis_t, param4) }, \
         } \
}
#endif

/**
 * @brief Pack a task_mission_down_mis message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  waypoint sequence
 * @param count  waypoint count
 * @param type  waypoint type, see enum(TASK_MISSION_TYPE).
 * @param lat  waypoint latitude
 * @param lon  waypoint longitude
 * @param alt  waypoint altitude
 * @param gb_pitch  gimbal pitch value -1f..1f
 * @param uav_yaw  vehicle global yaw
 * @param action  vehicle and camera execution. see enum(TASK_ACTION).
 * @param velocity  flight velocity, unit is meters.
 * @param param1  Reserved 
 * @param param2  Reserved 
 * @param param3  Reserved 
 * @param param4  Reserved 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_down_mis_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t index, int16_t count, int16_t type, float lat, float lon, float alt, float gb_pitch, float uav_yaw, float action, float velocity, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_float(buf, 8, alt);
    _mav_put_float(buf, 12, gb_pitch);
    _mav_put_float(buf, 16, uav_yaw);
    _mav_put_float(buf, 20, action);
    _mav_put_float(buf, 24, velocity);
    _mav_put_float(buf, 28, param1);
    _mav_put_float(buf, 32, param2);
    _mav_put_float(buf, 36, param3);
    _mav_put_float(buf, 40, param4);
    _mav_put_int16_t(buf, 44, index);
    _mav_put_int16_t(buf, 46, count);
    _mav_put_int16_t(buf, 48, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN);
#else
    mavlink_task_mission_down_mis_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.gb_pitch = gb_pitch;
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

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_CRC);
}

/**
 * @brief Pack a task_mission_down_mis message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  waypoint sequence
 * @param count  waypoint count
 * @param type  waypoint type, see enum(TASK_MISSION_TYPE).
 * @param lat  waypoint latitude
 * @param lon  waypoint longitude
 * @param alt  waypoint altitude
 * @param gb_pitch  gimbal pitch value -1f..1f
 * @param uav_yaw  vehicle global yaw
 * @param action  vehicle and camera execution. see enum(TASK_ACTION).
 * @param velocity  flight velocity, unit is meters.
 * @param param1  Reserved 
 * @param param2  Reserved 
 * @param param3  Reserved 
 * @param param4  Reserved 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_mission_down_mis_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t index,int16_t count,int16_t type,float lat,float lon,float alt,float gb_pitch,float uav_yaw,float action,float velocity,float param1,float param2,float param3,float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_float(buf, 8, alt);
    _mav_put_float(buf, 12, gb_pitch);
    _mav_put_float(buf, 16, uav_yaw);
    _mav_put_float(buf, 20, action);
    _mav_put_float(buf, 24, velocity);
    _mav_put_float(buf, 28, param1);
    _mav_put_float(buf, 32, param2);
    _mav_put_float(buf, 36, param3);
    _mav_put_float(buf, 40, param4);
    _mav_put_int16_t(buf, 44, index);
    _mav_put_int16_t(buf, 46, count);
    _mav_put_int16_t(buf, 48, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN);
#else
    mavlink_task_mission_down_mis_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.gb_pitch = gb_pitch;
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

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_CRC);
}

/**
 * @brief Encode a task_mission_down_mis struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_down_mis C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_down_mis_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_task_mission_down_mis_t* task_mission_down_mis)
{
    return mavlink_msg_task_mission_down_mis_pack(system_id, component_id, msg, task_mission_down_mis->index, task_mission_down_mis->count, task_mission_down_mis->type, task_mission_down_mis->lat, task_mission_down_mis->lon, task_mission_down_mis->alt, task_mission_down_mis->gb_pitch, task_mission_down_mis->uav_yaw, task_mission_down_mis->action, task_mission_down_mis->velocity, task_mission_down_mis->param1, task_mission_down_mis->param2, task_mission_down_mis->param3, task_mission_down_mis->param4);
}

/**
 * @brief Encode a task_mission_down_mis struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param task_mission_down_mis C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_mission_down_mis_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_task_mission_down_mis_t* task_mission_down_mis)
{
    return mavlink_msg_task_mission_down_mis_pack_chan(system_id, component_id, chan, msg, task_mission_down_mis->index, task_mission_down_mis->count, task_mission_down_mis->type, task_mission_down_mis->lat, task_mission_down_mis->lon, task_mission_down_mis->alt, task_mission_down_mis->gb_pitch, task_mission_down_mis->uav_yaw, task_mission_down_mis->action, task_mission_down_mis->velocity, task_mission_down_mis->param1, task_mission_down_mis->param2, task_mission_down_mis->param3, task_mission_down_mis->param4);
}

/**
 * @brief Send a task_mission_down_mis message
 * @param chan MAVLink channel to send the message
 *
 * @param index  waypoint sequence
 * @param count  waypoint count
 * @param type  waypoint type, see enum(TASK_MISSION_TYPE).
 * @param lat  waypoint latitude
 * @param lon  waypoint longitude
 * @param alt  waypoint altitude
 * @param gb_pitch  gimbal pitch value -1f..1f
 * @param uav_yaw  vehicle global yaw
 * @param action  vehicle and camera execution. see enum(TASK_ACTION).
 * @param velocity  flight velocity, unit is meters.
 * @param param1  Reserved 
 * @param param2  Reserved 
 * @param param3  Reserved 
 * @param param4  Reserved 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_mission_down_mis_send(mavlink_channel_t chan, int16_t index, int16_t count, int16_t type, float lat, float lon, float alt, float gb_pitch, float uav_yaw, float action, float velocity, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_float(buf, 8, alt);
    _mav_put_float(buf, 12, gb_pitch);
    _mav_put_float(buf, 16, uav_yaw);
    _mav_put_float(buf, 20, action);
    _mav_put_float(buf, 24, velocity);
    _mav_put_float(buf, 28, param1);
    _mav_put_float(buf, 32, param2);
    _mav_put_float(buf, 36, param3);
    _mav_put_float(buf, 40, param4);
    _mav_put_int16_t(buf, 44, index);
    _mav_put_int16_t(buf, 46, count);
    _mav_put_int16_t(buf, 48, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS, buf, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_CRC);
#else
    mavlink_task_mission_down_mis_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.gb_pitch = gb_pitch;
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS, (const char *)&packet, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_CRC);
#endif
}

/**
 * @brief Send a task_mission_down_mis message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_task_mission_down_mis_send_struct(mavlink_channel_t chan, const mavlink_task_mission_down_mis_t* task_mission_down_mis)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_task_mission_down_mis_send(chan, task_mission_down_mis->index, task_mission_down_mis->count, task_mission_down_mis->type, task_mission_down_mis->lat, task_mission_down_mis->lon, task_mission_down_mis->alt, task_mission_down_mis->gb_pitch, task_mission_down_mis->uav_yaw, task_mission_down_mis->action, task_mission_down_mis->velocity, task_mission_down_mis->param1, task_mission_down_mis->param2, task_mission_down_mis->param3, task_mission_down_mis->param4);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS, (const char *)task_mission_down_mis, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_mission_down_mis_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t index, int16_t count, int16_t type, float lat, float lon, float alt, float gb_pitch, float uav_yaw, float action, float velocity, float param1, float param2, float param3, float param4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_float(buf, 8, alt);
    _mav_put_float(buf, 12, gb_pitch);
    _mav_put_float(buf, 16, uav_yaw);
    _mav_put_float(buf, 20, action);
    _mav_put_float(buf, 24, velocity);
    _mav_put_float(buf, 28, param1);
    _mav_put_float(buf, 32, param2);
    _mav_put_float(buf, 36, param3);
    _mav_put_float(buf, 40, param4);
    _mav_put_int16_t(buf, 44, index);
    _mav_put_int16_t(buf, 46, count);
    _mav_put_int16_t(buf, 48, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS, buf, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_CRC);
#else
    mavlink_task_mission_down_mis_t *packet = (mavlink_task_mission_down_mis_t *)msgbuf;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;
    packet->gb_pitch = gb_pitch;
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS, (const char *)packet, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_MIN_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_MISSION_DOWN_MIS UNPACKING


/**
 * @brief Get field index from task_mission_down_mis message
 *
 * @return  waypoint sequence
 */
static inline int16_t mavlink_msg_task_mission_down_mis_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  44);
}

/**
 * @brief Get field count from task_mission_down_mis message
 *
 * @return  waypoint count
 */
static inline int16_t mavlink_msg_task_mission_down_mis_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  46);
}

/**
 * @brief Get field type from task_mission_down_mis message
 *
 * @return  waypoint type, see enum(TASK_MISSION_TYPE).
 */
static inline int16_t mavlink_msg_task_mission_down_mis_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  48);
}

/**
 * @brief Get field lat from task_mission_down_mis message
 *
 * @return  waypoint latitude
 */
static inline float mavlink_msg_task_mission_down_mis_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field lon from task_mission_down_mis message
 *
 * @return  waypoint longitude
 */
static inline float mavlink_msg_task_mission_down_mis_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field alt from task_mission_down_mis message
 *
 * @return  waypoint altitude
 */
static inline float mavlink_msg_task_mission_down_mis_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field gb_pitch from task_mission_down_mis message
 *
 * @return  gimbal pitch value -1f..1f
 */
static inline float mavlink_msg_task_mission_down_mis_get_gb_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field uav_yaw from task_mission_down_mis message
 *
 * @return  vehicle global yaw
 */
static inline float mavlink_msg_task_mission_down_mis_get_uav_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field action from task_mission_down_mis message
 *
 * @return  vehicle and camera execution. see enum(TASK_ACTION).
 */
static inline float mavlink_msg_task_mission_down_mis_get_action(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field velocity from task_mission_down_mis message
 *
 * @return  flight velocity, unit is meters.
 */
static inline float mavlink_msg_task_mission_down_mis_get_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field param1 from task_mission_down_mis message
 *
 * @return  Reserved 
 */
static inline float mavlink_msg_task_mission_down_mis_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field param2 from task_mission_down_mis message
 *
 * @return  Reserved 
 */
static inline float mavlink_msg_task_mission_down_mis_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field param3 from task_mission_down_mis message
 *
 * @return  Reserved 
 */
static inline float mavlink_msg_task_mission_down_mis_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field param4 from task_mission_down_mis message
 *
 * @return  Reserved 
 */
static inline float mavlink_msg_task_mission_down_mis_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Decode a task_mission_down_mis message into a struct
 *
 * @param msg The message to decode
 * @param task_mission_down_mis C-struct to decode the message contents into
 */
static inline void mavlink_msg_task_mission_down_mis_decode(const mavlink_message_t* msg, mavlink_task_mission_down_mis_t* task_mission_down_mis)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    task_mission_down_mis->lat = mavlink_msg_task_mission_down_mis_get_lat(msg);
    task_mission_down_mis->lon = mavlink_msg_task_mission_down_mis_get_lon(msg);
    task_mission_down_mis->alt = mavlink_msg_task_mission_down_mis_get_alt(msg);
    task_mission_down_mis->gb_pitch = mavlink_msg_task_mission_down_mis_get_gb_pitch(msg);
    task_mission_down_mis->uav_yaw = mavlink_msg_task_mission_down_mis_get_uav_yaw(msg);
    task_mission_down_mis->action = mavlink_msg_task_mission_down_mis_get_action(msg);
    task_mission_down_mis->velocity = mavlink_msg_task_mission_down_mis_get_velocity(msg);
    task_mission_down_mis->param1 = mavlink_msg_task_mission_down_mis_get_param1(msg);
    task_mission_down_mis->param2 = mavlink_msg_task_mission_down_mis_get_param2(msg);
    task_mission_down_mis->param3 = mavlink_msg_task_mission_down_mis_get_param3(msg);
    task_mission_down_mis->param4 = mavlink_msg_task_mission_down_mis_get_param4(msg);
    task_mission_down_mis->index = mavlink_msg_task_mission_down_mis_get_index(msg);
    task_mission_down_mis->count = mavlink_msg_task_mission_down_mis_get_count(msg);
    task_mission_down_mis->type = mavlink_msg_task_mission_down_mis_get_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN? msg->len : MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN;
        memset(task_mission_down_mis, 0, MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_LEN);
    memcpy(task_mission_down_mis, _MAV_PAYLOAD(msg), len);
#endif
}
