/** @file
 *    @brief MAVLink comm protocol testsuite generated from goertek.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef GOERTEK_TESTSUITE_H
#define GOERTEK_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_goertek(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_goertek(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_visual_tracking(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_VISUAL_TRACKING >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_visual_tracking_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,213.0,101
    };
    mavlink_visual_tracking_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.width = packet_in.width;
        packet1.height = packet_in.height;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.center_x = packet_in.center_x;
        packet1.center_y = packet_in.center_y;
        packet1.track_quality = packet_in.track_quality;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_VISUAL_TRACKING_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_VISUAL_TRACKING_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_visual_tracking_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_visual_tracking_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_visual_tracking_pack(system_id, component_id, &msg , packet1.time_usec , packet1.track_quality , packet1.width , packet1.height , packet1.x , packet1.y , packet1.center_x , packet1.center_y );
    mavlink_msg_visual_tracking_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_visual_tracking_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.track_quality , packet1.width , packet1.height , packet1.x , packet1.y , packet1.center_x , packet1.center_y );
    mavlink_msg_visual_tracking_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_visual_tracking_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_visual_tracking_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.track_quality , packet1.width , packet1.height , packet1.x , packet1.y , packet1.center_x , packet1.center_y );
    mavlink_msg_visual_tracking_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("VISUAL_TRACKING") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_VISUAL_TRACKING) != NULL);
#endif
}

static void mavlink_test_task_up_mis(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_UP_MIS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_up_mis_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,18691,18795
    };
    mavlink_task_up_mis_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.alt = packet_in.alt;
        packet1.gb_pitch = packet_in.gb_pitch;
        packet1.uav_yaw = packet_in.uav_yaw;
        packet1.action = packet_in.action;
        packet1.velocity = packet_in.velocity;
        packet1.index = packet_in.index;
        packet1.count = packet_in.count;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_UP_MIS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_UP_MIS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_up_mis_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_up_mis_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_up_mis_pack(system_id, component_id, &msg , packet1.index , packet1.count , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.uav_yaw , packet1.action , packet1.velocity );
    mavlink_msg_task_up_mis_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_up_mis_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.index , packet1.count , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.uav_yaw , packet1.action , packet1.velocity );
    mavlink_msg_task_up_mis_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_up_mis_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_up_mis_send(MAVLINK_COMM_1 , packet1.index , packet1.count , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.uav_yaw , packet1.action , packet1.velocity );
    mavlink_msg_task_up_mis_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_UP_MIS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_UP_MIS) != NULL);
#endif
}

static void mavlink_test_task_down_mis(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_DOWN_MIS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_down_mis_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,18691,18795
    };
    mavlink_task_down_mis_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.alt = packet_in.alt;
        packet1.gb_pitch = packet_in.gb_pitch;
        packet1.uav_yaw = packet_in.uav_yaw;
        packet1.action = packet_in.action;
        packet1.velocity = packet_in.velocity;
        packet1.index = packet_in.index;
        packet1.count = packet_in.count;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_DOWN_MIS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_DOWN_MIS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_down_mis_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_down_mis_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_down_mis_pack(system_id, component_id, &msg , packet1.index , packet1.count , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.uav_yaw , packet1.action , packet1.velocity );
    mavlink_msg_task_down_mis_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_down_mis_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.index , packet1.count , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.uav_yaw , packet1.action , packet1.velocity );
    mavlink_msg_task_down_mis_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_down_mis_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_down_mis_send(MAVLINK_COMM_1 , packet1.index , packet1.count , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.uav_yaw , packet1.action , packet1.velocity );
    mavlink_msg_task_down_mis_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_DOWN_MIS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_DOWN_MIS) != NULL);
#endif
}

static void mavlink_test_task_request_list(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_REQUEST_LIST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_request_list_t packet_in = {
        5,72,139
    };
    mavlink_task_request_list_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.type = packet_in.type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_REQUEST_LIST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_REQUEST_LIST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_request_list_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_request_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_request_list_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.type );
    mavlink_msg_task_request_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_request_list_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.type );
    mavlink_msg_task_request_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_request_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_request_list_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.type );
    mavlink_msg_task_request_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_REQUEST_LIST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_REQUEST_LIST) != NULL);
#endif
}

static void mavlink_test_task_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_ack_t packet_in = {
        5,72,139
    };
    mavlink_task_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.result = packet_in.result;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_ack_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.result );
    mavlink_msg_task_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.result );
    mavlink_msg_task_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_ack_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.result );
    mavlink_msg_task_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_ACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_ACK) != NULL);
#endif
}

static void mavlink_test_task_state_feedback(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_STATE_FEEDBACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_state_feedback_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,89,156
    };
    mavlink_task_state_feedback_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param1 = packet_in.param1;
        packet1.param2 = packet_in.param2;
        packet1.param3 = packet_in.param3;
        packet1.param4 = packet_in.param4;
        packet1.param5 = packet_in.param5;
        packet1.param6 = packet_in.param6;
        packet1.param7 = packet_in.param7;
        packet1.task_mode = packet_in.task_mode;
        packet1.task_state = packet_in.task_state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_STATE_FEEDBACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_STATE_FEEDBACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_state_feedback_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_state_feedback_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_state_feedback_pack(system_id, component_id, &msg , packet1.task_mode , packet1.task_state , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.param5 , packet1.param6 , packet1.param7 );
    mavlink_msg_task_state_feedback_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_state_feedback_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.task_mode , packet1.task_state , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.param5 , packet1.param6 , packet1.param7 );
    mavlink_msg_task_state_feedback_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_state_feedback_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_state_feedback_send(MAVLINK_COMM_1 , packet1.task_mode , packet1.task_state , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.param5 , packet1.param6 , packet1.param7 );
    mavlink_msg_task_state_feedback_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_STATE_FEEDBACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_STATE_FEEDBACK) != NULL);
#endif
}

static void mavlink_test_vision_modules_versions(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_VISION_MODULES_VERSIONS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_vision_modules_versions_t packet_in = {
        963497464,963497672,963497880,963498088
    };
    mavlink_vision_modules_versions_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.optical_software_version = packet_in.optical_software_version;
        packet1.optical_hardware_version = packet_in.optical_hardware_version;
        packet1.realsense_software_version = packet_in.realsense_software_version;
        packet1.realsense_hardware_version = packet_in.realsense_hardware_version;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_VISION_MODULES_VERSIONS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_VISION_MODULES_VERSIONS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vision_modules_versions_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_vision_modules_versions_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vision_modules_versions_pack(system_id, component_id, &msg , packet1.optical_software_version , packet1.optical_hardware_version , packet1.realsense_software_version , packet1.realsense_hardware_version );
    mavlink_msg_vision_modules_versions_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vision_modules_versions_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.optical_software_version , packet1.optical_hardware_version , packet1.realsense_software_version , packet1.realsense_hardware_version );
    mavlink_msg_vision_modules_versions_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_vision_modules_versions_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vision_modules_versions_send(MAVLINK_COMM_1 , packet1.optical_software_version , packet1.optical_hardware_version , packet1.realsense_software_version , packet1.realsense_hardware_version );
    mavlink_msg_vision_modules_versions_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("VISION_MODULES_VERSIONS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_VISION_MODULES_VERSIONS) != NULL);
#endif
}

static void mavlink_test_estimator_mode_additions(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ESTIMATOR_MODE_ADDITIONS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_estimator_mode_additions_t packet_in = {
        963497464
    };
    mavlink_estimator_mode_additions_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.estimator_mode = packet_in.estimator_mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ESTIMATOR_MODE_ADDITIONS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ESTIMATOR_MODE_ADDITIONS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_estimator_mode_additions_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_estimator_mode_additions_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_estimator_mode_additions_pack(system_id, component_id, &msg , packet1.estimator_mode );
    mavlink_msg_estimator_mode_additions_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_estimator_mode_additions_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.estimator_mode );
    mavlink_msg_estimator_mode_additions_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_estimator_mode_additions_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_estimator_mode_additions_send(MAVLINK_COMM_1 , packet1.estimator_mode );
    mavlink_msg_estimator_mode_additions_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("ESTIMATOR_MODE_ADDITIONS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_ESTIMATOR_MODE_ADDITIONS) != NULL);
#endif
}

static void mavlink_test_no_fly_zone_unlocking(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_NO_FLY_ZONE_UNLOCKING >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_no_fly_zone_unlocking_t packet_in = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEF"
    };
    mavlink_no_fly_zone_unlocking_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.no_fly_zone_key, packet_in.no_fly_zone_key, sizeof(char)*33);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_NO_FLY_ZONE_UNLOCKING_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_NO_FLY_ZONE_UNLOCKING_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_no_fly_zone_unlocking_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_no_fly_zone_unlocking_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_no_fly_zone_unlocking_pack(system_id, component_id, &msg , packet1.no_fly_zone_key );
    mavlink_msg_no_fly_zone_unlocking_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_no_fly_zone_unlocking_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.no_fly_zone_key );
    mavlink_msg_no_fly_zone_unlocking_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_no_fly_zone_unlocking_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_no_fly_zone_unlocking_send(MAVLINK_COMM_1 , packet1.no_fly_zone_key );
    mavlink_msg_no_fly_zone_unlocking_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("NO_FLY_ZONE_UNLOCKING") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_NO_FLY_ZONE_UNLOCKING) != NULL);
#endif
}

static void mavlink_test_yuneec_optical_flow_rad(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_YUNEEC_OPTICAL_FLOW_RAD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_yuneec_optical_flow_rad_t packet_in = {
        93372036854775807ULL,963497880,101.0,129.0,157.0,185.0,213.0,963499128,269.0,963499544,19523,15,82,149,216
    };
    mavlink_yuneec_optical_flow_rad_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.integration_time_us = packet_in.integration_time_us;
        packet1.integrated_x = packet_in.integrated_x;
        packet1.integrated_y = packet_in.integrated_y;
        packet1.integrated_xgyro = packet_in.integrated_xgyro;
        packet1.integrated_ygyro = packet_in.integrated_ygyro;
        packet1.integrated_zgyro = packet_in.integrated_zgyro;
        packet1.time_delta_distance_us = packet_in.time_delta_distance_us;
        packet1.distance = packet_in.distance;
        packet1.distance_count = packet_in.distance_count;
        packet1.temperature = packet_in.temperature;
        packet1.sensor_id = packet_in.sensor_id;
        packet1.quality = packet_in.quality;
        packet1.sonar_level = packet_in.sonar_level;
        packet1.luminance = packet_in.luminance;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_YUNEEC_OPTICAL_FLOW_RAD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_YUNEEC_OPTICAL_FLOW_RAD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_yuneec_optical_flow_rad_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_yuneec_optical_flow_rad_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_yuneec_optical_flow_rad_pack(system_id, component_id, &msg , packet1.time_usec , packet1.sensor_id , packet1.integration_time_us , packet1.integrated_x , packet1.integrated_y , packet1.integrated_xgyro , packet1.integrated_ygyro , packet1.integrated_zgyro , packet1.temperature , packet1.quality , packet1.time_delta_distance_us , packet1.distance , packet1.sonar_level , packet1.luminance , packet1.distance_count );
    mavlink_msg_yuneec_optical_flow_rad_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_yuneec_optical_flow_rad_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.sensor_id , packet1.integration_time_us , packet1.integrated_x , packet1.integrated_y , packet1.integrated_xgyro , packet1.integrated_ygyro , packet1.integrated_zgyro , packet1.temperature , packet1.quality , packet1.time_delta_distance_us , packet1.distance , packet1.sonar_level , packet1.luminance , packet1.distance_count );
    mavlink_msg_yuneec_optical_flow_rad_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_yuneec_optical_flow_rad_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_yuneec_optical_flow_rad_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.sensor_id , packet1.integration_time_us , packet1.integrated_x , packet1.integrated_y , packet1.integrated_xgyro , packet1.integrated_ygyro , packet1.integrated_zgyro , packet1.temperature , packet1.quality , packet1.time_delta_distance_us , packet1.distance , packet1.sonar_level , packet1.luminance , packet1.distance_count );
    mavlink_msg_yuneec_optical_flow_rad_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("YUNEEC_OPTICAL_FLOW_RAD") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_YUNEEC_OPTICAL_FLOW_RAD) != NULL);
#endif
}

static void mavlink_test_nfz_unlock_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_NFZ_UNLOCK_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_nfz_unlock_status_t packet_in = {
        963497464,963497672,963497880,41
    };
    mavlink_nfz_unlock_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.uuid_verified = packet_in.uuid_verified;
        packet1.time_limit = packet_in.time_limit;
        packet1.board_uuid_h = packet_in.board_uuid_h;
        packet1.status = packet_in.status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_NFZ_UNLOCK_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_NFZ_UNLOCK_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_nfz_unlock_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_nfz_unlock_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_nfz_unlock_status_pack(system_id, component_id, &msg , packet1.status , packet1.uuid_verified , packet1.time_limit , packet1.board_uuid_h );
    mavlink_msg_nfz_unlock_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_nfz_unlock_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.status , packet1.uuid_verified , packet1.time_limit , packet1.board_uuid_h );
    mavlink_msg_nfz_unlock_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_nfz_unlock_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_nfz_unlock_status_send(MAVLINK_COMM_1 , packet1.status , packet1.uuid_verified , packet1.time_limit , packet1.board_uuid_h );
    mavlink_msg_nfz_unlock_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("NFZ_UNLOCK_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_NFZ_UNLOCK_STATUS) != NULL);
#endif
}

static void mavlink_test_task_mission_item(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_MISSION_ITEM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_mission_item_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,19731,19835,19939,39
    };
    mavlink_task_mission_item_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.alt = packet_in.alt;
        packet1.gb_pitch = packet_in.gb_pitch;
        packet1.gb_yaw = packet_in.gb_yaw;
        packet1.uav_yaw = packet_in.uav_yaw;
        packet1.action = packet_in.action;
        packet1.velocity = packet_in.velocity;
        packet1.param1 = packet_in.param1;
        packet1.param2 = packet_in.param2;
        packet1.param3 = packet_in.param3;
        packet1.param4 = packet_in.param4;
        packet1.index = packet_in.index;
        packet1.count = packet_in.count;
        packet1.type = packet_in.type;
        packet1.frame = packet_in.frame;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_MISSION_ITEM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_MISSION_ITEM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_item_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_mission_item_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_item_pack(system_id, component_id, &msg , packet1.index , packet1.count , packet1.type , packet1.frame , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.gb_yaw , packet1.uav_yaw , packet1.action , packet1.velocity , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_item_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_item_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.index , packet1.count , packet1.type , packet1.frame , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.gb_yaw , packet1.uav_yaw , packet1.action , packet1.velocity , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_item_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_mission_item_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_item_send(MAVLINK_COMM_1 , packet1.index , packet1.count , packet1.type , packet1.frame , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.gb_yaw , packet1.uav_yaw , packet1.action , packet1.velocity , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_item_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_MISSION_ITEM") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_MISSION_ITEM) != NULL);
#endif
}

static void mavlink_test_task_mission_down_mis(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_mission_down_mis_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,19523,19627,19731
    };
    mavlink_task_mission_down_mis_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.alt = packet_in.alt;
        packet1.gb_pitch = packet_in.gb_pitch;
        packet1.uav_yaw = packet_in.uav_yaw;
        packet1.action = packet_in.action;
        packet1.velocity = packet_in.velocity;
        packet1.param1 = packet_in.param1;
        packet1.param2 = packet_in.param2;
        packet1.param3 = packet_in.param3;
        packet1.param4 = packet_in.param4;
        packet1.index = packet_in.index;
        packet1.count = packet_in.count;
        packet1.type = packet_in.type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_down_mis_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_mission_down_mis_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_down_mis_pack(system_id, component_id, &msg , packet1.index , packet1.count , packet1.type , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.uav_yaw , packet1.action , packet1.velocity , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_down_mis_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_down_mis_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.index , packet1.count , packet1.type , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.uav_yaw , packet1.action , packet1.velocity , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_down_mis_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_mission_down_mis_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_down_mis_send(MAVLINK_COMM_1 , packet1.index , packet1.count , packet1.type , packet1.lat , packet1.lon , packet1.alt , packet1.gb_pitch , packet1.uav_yaw , packet1.action , packet1.velocity , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_down_mis_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_MISSION_DOWN_MIS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_MISSION_DOWN_MIS) != NULL);
#endif
}

static void mavlink_test_ync_param_ext_value(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_YNC_PARAM_EXT_VALUE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ync_param_ext_value_t packet_in = {
        17235,17339,17,"FGHIJKLMNOPQRST","VWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQR"
    };
    mavlink_ync_param_ext_value_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param_count = packet_in.param_count;
        packet1.param_index = packet_in.param_index;
        packet1.param_type = packet_in.param_type;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        mav_array_memcpy(packet1.param_value, packet_in.param_value, sizeof(char)*128);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_YNC_PARAM_EXT_VALUE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_YNC_PARAM_EXT_VALUE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_value_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ync_param_ext_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_value_pack(system_id, component_id, &msg , packet1.param_type , packet1.param_count , packet1.param_index , packet1.param_id , packet1.param_value );
    mavlink_msg_ync_param_ext_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_value_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.param_type , packet1.param_count , packet1.param_index , packet1.param_id , packet1.param_value );
    mavlink_msg_ync_param_ext_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ync_param_ext_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_value_send(MAVLINK_COMM_1 , packet1.param_type , packet1.param_count , packet1.param_index , packet1.param_id , packet1.param_value );
    mavlink_msg_ync_param_ext_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("YNC_PARAM_EXT_VALUE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_YNC_PARAM_EXT_VALUE) != NULL);
#endif
}

static void mavlink_test_ync_param_ext_set(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_YNC_PARAM_EXT_SET >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ync_param_ext_set_t packet_in = {
        5,72,139,"DEFGHIJKLMNOPQR","TUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOP"
    };
    mavlink_ync_param_ext_set_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.param_type = packet_in.param_type;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        mav_array_memcpy(packet1.param_value, packet_in.param_value, sizeof(char)*128);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_YNC_PARAM_EXT_SET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_YNC_PARAM_EXT_SET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_set_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ync_param_ext_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_set_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.param_type , packet1.param_id , packet1.param_value );
    mavlink_msg_ync_param_ext_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_set_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.param_type , packet1.param_id , packet1.param_value );
    mavlink_msg_ync_param_ext_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ync_param_ext_set_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_set_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.param_type , packet1.param_id , packet1.param_value );
    mavlink_msg_ync_param_ext_set_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("YNC_PARAM_EXT_SET") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_YNC_PARAM_EXT_SET) != NULL);
#endif
}

static void mavlink_test_ync_param_ext_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_YNC_PARAM_EXT_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ync_param_ext_ack_t packet_in = {
        5,72,"CDEFGHIJKLMNOPQ","STUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNO"
    };
    mavlink_ync_param_ext_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param_type = packet_in.param_type;
        packet1.param_result = packet_in.param_result;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        mav_array_memcpy(packet1.param_value, packet_in.param_value, sizeof(char)*128);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_YNC_PARAM_EXT_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_YNC_PARAM_EXT_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ync_param_ext_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_ack_pack(system_id, component_id, &msg , packet1.param_type , packet1.param_result , packet1.param_id , packet1.param_value );
    mavlink_msg_ync_param_ext_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.param_type , packet1.param_result , packet1.param_id , packet1.param_value );
    mavlink_msg_ync_param_ext_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ync_param_ext_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_ack_send(MAVLINK_COMM_1 , packet1.param_type , packet1.param_result , packet1.param_id , packet1.param_value );
    mavlink_msg_ync_param_ext_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("YNC_PARAM_EXT_ACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_YNC_PARAM_EXT_ACK) != NULL);
#endif
}

static void mavlink_test_ync_param_ext_request_read(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_YNC_PARAM_EXT_REQUEST_READ >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ync_param_ext_request_read_t packet_in = {
        17235,139,206,"EFGHIJKLMNOPQRS"
    };
    mavlink_ync_param_ext_request_read_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param_index = packet_in.param_index;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_YNC_PARAM_EXT_REQUEST_READ_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_YNC_PARAM_EXT_REQUEST_READ_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_request_read_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ync_param_ext_request_read_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_request_read_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.param_index , packet1.param_id );
    mavlink_msg_ync_param_ext_request_read_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_request_read_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.param_index , packet1.param_id );
    mavlink_msg_ync_param_ext_request_read_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ync_param_ext_request_read_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_request_read_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.param_index , packet1.param_id );
    mavlink_msg_ync_param_ext_request_read_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("YNC_PARAM_EXT_REQUEST_READ") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_YNC_PARAM_EXT_REQUEST_READ) != NULL);
#endif
}

static void mavlink_test_ync_param_ext_request_list(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_YNC_PARAM_EXT_REQUEST_LIST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ync_param_ext_request_list_t packet_in = {
        5,72
    };
    mavlink_ync_param_ext_request_list_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_YNC_PARAM_EXT_REQUEST_LIST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_YNC_PARAM_EXT_REQUEST_LIST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_request_list_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ync_param_ext_request_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_request_list_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component );
    mavlink_msg_ync_param_ext_request_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_request_list_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component );
    mavlink_msg_ync_param_ext_request_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ync_param_ext_request_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ync_param_ext_request_list_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component );
    mavlink_msg_ync_param_ext_request_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("YNC_PARAM_EXT_REQUEST_LIST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_YNC_PARAM_EXT_REQUEST_LIST) != NULL);
#endif
}

static void mavlink_test_exposure_event_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EXPOSURE_EVENT_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_exposure_event_request_t packet_in = {
        5,72
    };
    mavlink_exposure_event_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EXPOSURE_EVENT_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EXPOSURE_EVENT_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exposure_event_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_exposure_event_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exposure_event_request_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component );
    mavlink_msg_exposure_event_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exposure_event_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component );
    mavlink_msg_exposure_event_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_exposure_event_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exposure_event_request_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component );
    mavlink_msg_exposure_event_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("EXPOSURE_EVENT_REQUEST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_EXPOSURE_EVENT_REQUEST) != NULL);
#endif
}

static void mavlink_test_exposure_event_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_exposure_event_ack_t packet_in = {
        123.0,179.0,963498296,963498504,963498712,963498920,241.0,269.0,297.0,325.0,353.0,381.0
    };
    mavlink_exposure_event_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.week = packet_in.week;
        packet1.second = packet_in.second;
        packet1.subsecond = packet_in.subsecond;
        packet1.alt = packet_in.alt;
        packet1.lat_err = packet_in.lat_err;
        packet1.lon_err = packet_in.lon_err;
        packet1.alt_err = packet_in.alt_err;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exposure_event_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_exposure_event_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exposure_event_ack_pack(system_id, component_id, &msg , packet1.week , packet1.second , packet1.subsecond , packet1.lat , packet1.lon , packet1.alt , packet1.lat_err , packet1.lon_err , packet1.alt_err , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_exposure_event_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exposure_event_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.week , packet1.second , packet1.subsecond , packet1.lat , packet1.lon , packet1.alt , packet1.lat_err , packet1.lon_err , packet1.alt_err , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_exposure_event_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_exposure_event_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exposure_event_ack_send(MAVLINK_COMM_1 , packet1.week , packet1.second , packet1.subsecond , packet1.lat , packet1.lon , packet1.alt , packet1.lat_err , packet1.lon_err , packet1.alt_err , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_exposure_event_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("EXPOSURE_EVENT_ACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_EXPOSURE_EVENT_ACK) != NULL);
#endif
}

static void mavlink_test_task_mission_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_MISSION_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_mission_ack_t packet_in = {
        963497464,45.0,73.0,41,108,175,242
    };
    mavlink_task_mission_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.index = packet_in.index;
        packet1.param1 = packet_in.param1;
        packet1.param2 = packet_in.param2;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.result = packet_in.result;
        packet1.task_mission_type = packet_in.task_mission_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_MISSION_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_MISSION_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_mission_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_ack_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.result , packet1.task_mission_type , packet1.index , packet1.param1 , packet1.param2 );
    mavlink_msg_task_mission_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.result , packet1.task_mission_type , packet1.index , packet1.param1 , packet1.param2 );
    mavlink_msg_task_mission_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_mission_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_ack_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.result , packet1.task_mission_type , packet1.index , packet1.param1 , packet1.param2 );
    mavlink_msg_task_mission_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_MISSION_ACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_MISSION_ACK) != NULL);
#endif
}

static void mavlink_test_task_mission_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_MISSION_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_mission_state_t packet_in = {
        17.0,45.0,73.0,101.0,18067,18171,18275,199
    };
    mavlink_task_mission_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param1 = packet_in.param1;
        packet1.param2 = packet_in.param2;
        packet1.param3 = packet_in.param3;
        packet1.param4 = packet_in.param4;
        packet1.count = packet_in.count;
        packet1.current_seq = packet_in.current_seq;
        packet1.interest_seq = packet_in.interest_seq;
        packet1.task_mission_type = packet_in.task_mission_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_MISSION_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_MISSION_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_mission_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_state_pack(system_id, component_id, &msg , packet1.count , packet1.current_seq , packet1.interest_seq , packet1.task_mission_type , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.count , packet1.current_seq , packet1.interest_seq , packet1.task_mission_type , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_mission_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_state_send(MAVLINK_COMM_1 , packet1.count , packet1.current_seq , packet1.interest_seq , packet1.task_mission_type , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_MISSION_STATE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_MISSION_STATE) != NULL);
#endif
}

static void mavlink_test_task_mission_state_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_MISSION_STATE_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_mission_state_request_t packet_in = {
        5,72,139
    };
    mavlink_task_mission_state_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.task_mission_type = packet_in.task_mission_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_MISSION_STATE_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_MISSION_STATE_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_state_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_mission_state_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_state_request_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.task_mission_type );
    mavlink_msg_task_mission_state_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_state_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.task_mission_type );
    mavlink_msg_task_mission_state_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_mission_state_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_state_request_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.task_mission_type );
    mavlink_msg_task_mission_state_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_MISSION_STATE_REQUEST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_MISSION_STATE_REQUEST) != NULL);
#endif
}

static void mavlink_test_task_mission_manage(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_MISSION_MANAGE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_mission_manage_t packet_in = {
        17.0,45.0,73.0,101.0,18067,187,254,65,132
    };
    mavlink_task_mission_manage_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param1 = packet_in.param1;
        packet1.param2 = packet_in.param2;
        packet1.param3 = packet_in.param3;
        packet1.param4 = packet_in.param4;
        packet1.seq = packet_in.seq;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.task_mission_type = packet_in.task_mission_type;
        packet1.cmd = packet_in.cmd;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_MISSION_MANAGE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_MISSION_MANAGE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_manage_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_mission_manage_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_manage_pack(system_id, component_id, &msg , packet1.seq , packet1.target_system , packet1.target_component , packet1.task_mission_type , packet1.cmd , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_manage_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_manage_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.seq , packet1.target_system , packet1.target_component , packet1.task_mission_type , packet1.cmd , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_manage_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_mission_manage_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_manage_send(MAVLINK_COMM_1 , packet1.seq , packet1.target_system , packet1.target_component , packet1.task_mission_type , packet1.cmd , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 );
    mavlink_msg_task_mission_manage_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_MISSION_MANAGE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_MISSION_MANAGE) != NULL);
#endif
}

static void mavlink_test_task_mission_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_MISSION_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_mission_request_t packet_in = {
        17235,139,206,17
    };
    mavlink_task_mission_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.seq = packet_in.seq;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.task_mission_type = packet_in.task_mission_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_MISSION_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_MISSION_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_mission_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_request_pack(system_id, component_id, &msg , packet1.seq , packet1.target_system , packet1.target_component , packet1.task_mission_type );
    mavlink_msg_task_mission_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.seq , packet1.target_system , packet1.target_component , packet1.task_mission_type );
    mavlink_msg_task_mission_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_mission_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_request_send(MAVLINK_COMM_1 , packet1.seq , packet1.target_system , packet1.target_component , packet1.task_mission_type );
    mavlink_msg_task_mission_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_MISSION_REQUEST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_MISSION_REQUEST) != NULL);
#endif
}

static void mavlink_test_task_mission_waypoint_reached(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_mission_waypoint_reached_t packet_in = {
        17235
    };
    mavlink_task_mission_waypoint_reached_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.seq = packet_in.seq;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_waypoint_reached_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_mission_waypoint_reached_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_waypoint_reached_pack(system_id, component_id, &msg , packet1.seq );
    mavlink_msg_task_mission_waypoint_reached_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_waypoint_reached_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.seq );
    mavlink_msg_task_mission_waypoint_reached_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_mission_waypoint_reached_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_mission_waypoint_reached_send(MAVLINK_COMM_1 , packet1.seq );
    mavlink_msg_task_mission_waypoint_reached_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_MISSION_WAYPOINT_REACHED") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_MISSION_WAYPOINT_REACHED) != NULL);
#endif
}

static void mavlink_test_camera_notification_panorama(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_camera_notification_panorama_t packet_in = {
        17235,139,206,17,84
    };
    mavlink_camera_notification_panorama_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.number = packet_in.number;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.result = packet_in.result;
        packet1.index = packet_in.index;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_notification_panorama_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_camera_notification_panorama_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_notification_panorama_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.result , packet1.index , packet1.number );
    mavlink_msg_camera_notification_panorama_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_notification_panorama_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.result , packet1.index , packet1.number );
    mavlink_msg_camera_notification_panorama_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_camera_notification_panorama_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_notification_panorama_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.result , packet1.index , packet1.number );
    mavlink_msg_camera_notification_panorama_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CAMERA_NOTIFICATION_PANORAMA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CAMERA_NOTIFICATION_PANORAMA) != NULL);
#endif
}

static void mavlink_test_mission_action(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MISSION_ACTION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mission_action_t packet_in = {
        5,72,139,206
    };
    mavlink_mission_action_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.mission_action = packet_in.mission_action;
        packet1.mission_id = packet_in.mission_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MISSION_ACTION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MISSION_ACTION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_action_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mission_action_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_action_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.mission_action , packet1.mission_id );
    mavlink_msg_mission_action_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_action_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.mission_action , packet1.mission_id );
    mavlink_msg_mission_action_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mission_action_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_action_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.mission_action , packet1.mission_id );
    mavlink_msg_mission_action_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MISSION_ACTION") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MISSION_ACTION) != NULL);
#endif
}

static void mavlink_test_mission_action_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MISSION_ACTION_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mission_action_ack_t packet_in = {
        5,"BCDEFGHIJ"
    };
    mavlink_mission_action_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.result = packet_in.result;
        
        mav_array_memcpy(packet1.mission_folder, packet_in.mission_folder, sizeof(char)*10);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MISSION_ACTION_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MISSION_ACTION_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_action_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mission_action_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_action_ack_pack(system_id, component_id, &msg , packet1.result , packet1.mission_folder );
    mavlink_msg_mission_action_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_action_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.result , packet1.mission_folder );
    mavlink_msg_mission_action_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mission_action_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_action_ack_send(MAVLINK_COMM_1 , packet1.result , packet1.mission_folder );
    mavlink_msg_mission_action_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MISSION_ACTION_ACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MISSION_ACTION_ACK) != NULL);
#endif
}

static void mavlink_test_component_version_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_COMPONENT_VERSION_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_component_version_info_t packet_in = {
        17235,17339,17,84
    };
    mavlink_component_version_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.software_version_build = packet_in.software_version_build;
        packet1.hardware_version = packet_in.hardware_version;
        packet1.software_version_major = packet_in.software_version_major;
        packet1.software_version_minor = packet_in.software_version_minor;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_COMPONENT_VERSION_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_component_version_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_component_version_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_component_version_info_pack(system_id, component_id, &msg , packet1.software_version_major , packet1.software_version_minor , packet1.software_version_build , packet1.hardware_version );
    mavlink_msg_component_version_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_component_version_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.software_version_major , packet1.software_version_minor , packet1.software_version_build , packet1.hardware_version );
    mavlink_msg_component_version_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_component_version_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_component_version_info_send(MAVLINK_COMM_1 , packet1.software_version_major , packet1.software_version_minor , packet1.software_version_build , packet1.hardware_version );
    mavlink_msg_component_version_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("COMPONENT_VERSION_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_COMPONENT_VERSION_INFO) != NULL);
#endif
}

static void mavlink_test_gimbal_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GIMBAL_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gimbal_control_t packet_in = {
        { 17235, 17236, 17237, 17238 },17651,17755,17859,17963,18067,18171,18275,18379,18483
    };
    mavlink_gimbal_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.hvel = packet_in.hvel;
        packet1.hacc = packet_in.hacc;
        packet1.yaw_deg_desire = packet_in.yaw_deg_desire;
        packet1.yaw_channel = packet_in.yaw_channel;
        packet1.pitch_channel = packet_in.pitch_channel;
        packet1.roll_channel = packet_in.roll_channel;
        packet1.yaw_mode = packet_in.yaw_mode;
        packet1.pitch_mode = packet_in.pitch_mode;
        packet1.roll_mode = packet_in.roll_mode;
        
        mav_array_memcpy(packet1.quaternion, packet_in.quaternion, sizeof(int16_t)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GIMBAL_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GIMBAL_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gimbal_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_pack(system_id, component_id, &msg , packet1.quaternion , packet1.hvel , packet1.hacc , packet1.yaw_deg_desire , packet1.yaw_channel , packet1.pitch_channel , packet1.roll_channel , packet1.yaw_mode , packet1.pitch_mode , packet1.roll_mode );
    mavlink_msg_gimbal_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.quaternion , packet1.hvel , packet1.hacc , packet1.yaw_deg_desire , packet1.yaw_channel , packet1.pitch_channel , packet1.roll_channel , packet1.yaw_mode , packet1.pitch_mode , packet1.roll_mode );
    mavlink_msg_gimbal_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gimbal_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_send(MAVLINK_COMM_1 , packet1.quaternion , packet1.hvel , packet1.hacc , packet1.yaw_deg_desire , packet1.yaw_channel , packet1.pitch_channel , packet1.roll_channel , packet1.yaw_mode , packet1.pitch_mode , packet1.roll_mode );
    mavlink_msg_gimbal_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GIMBAL_CONTROL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GIMBAL_CONTROL) != NULL);
#endif
}

static void mavlink_test_gimbal_control_standard(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GIMBAL_CONTROL_STANDARD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gimbal_control_standard_t packet_in = {
        17.0,45.0,73.0,101.0,53,120,187,254
    };
    mavlink_gimbal_control_standard_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.yaw_channel = packet_in.yaw_channel;
        packet1.pitch_channel = packet_in.pitch_channel;
        packet1.roll_channel = packet_in.roll_channel;
        packet1.drones_yawvelocity_desire = packet_in.drones_yawvelocity_desire;
        packet1.priority = packet_in.priority;
        packet1.yaw_mode = packet_in.yaw_mode;
        packet1.pitch_mode = packet_in.pitch_mode;
        packet1.roll_mode = packet_in.roll_mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GIMBAL_CONTROL_STANDARD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GIMBAL_CONTROL_STANDARD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_standard_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gimbal_control_standard_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_standard_pack(system_id, component_id, &msg , packet1.priority , packet1.yaw_mode , packet1.pitch_mode , packet1.roll_mode , packet1.yaw_channel , packet1.pitch_channel , packet1.roll_channel , packet1.drones_yawvelocity_desire );
    mavlink_msg_gimbal_control_standard_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_standard_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.priority , packet1.yaw_mode , packet1.pitch_mode , packet1.roll_mode , packet1.yaw_channel , packet1.pitch_channel , packet1.roll_channel , packet1.drones_yawvelocity_desire );
    mavlink_msg_gimbal_control_standard_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gimbal_control_standard_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_standard_send(MAVLINK_COMM_1 , packet1.priority , packet1.yaw_mode , packet1.pitch_mode , packet1.roll_mode , packet1.yaw_channel , packet1.pitch_channel , packet1.roll_channel , packet1.drones_yawvelocity_desire );
    mavlink_msg_gimbal_control_standard_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GIMBAL_CONTROL_STANDARD") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GIMBAL_CONTROL_STANDARD) != NULL);
#endif
}

static void mavlink_test_gimbal_debugdata(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GIMBAL_DEBUGDATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gimbal_debugdata_t packet_in = {
        5,{ 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120 }
    };
    mavlink_gimbal_debugdata_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.msg_type = packet_in.msg_type;
        
        mav_array_memcpy(packet1.debug_data, packet_in.debug_data, sizeof(int8_t)*49);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GIMBAL_DEBUGDATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GIMBAL_DEBUGDATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_debugdata_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gimbal_debugdata_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_debugdata_pack(system_id, component_id, &msg , packet1.msg_type , packet1.debug_data );
    mavlink_msg_gimbal_debugdata_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_debugdata_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.msg_type , packet1.debug_data );
    mavlink_msg_gimbal_debugdata_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gimbal_debugdata_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_debugdata_send(MAVLINK_COMM_1 , packet1.msg_type , packet1.debug_data );
    mavlink_msg_gimbal_debugdata_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GIMBAL_DEBUGDATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GIMBAL_DEBUGDATA) != NULL);
#endif
}

static void mavlink_test_bootload_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BOOTLOAD_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_bootload_data_t packet_in = {
        { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137 }
    };
    mavlink_bootload_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.bootload_data, packet_in.bootload_data, sizeof(int8_t)*133);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BOOTLOAD_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BOOTLOAD_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bootload_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_bootload_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bootload_data_pack(system_id, component_id, &msg , packet1.bootload_data );
    mavlink_msg_bootload_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bootload_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.bootload_data );
    mavlink_msg_bootload_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_bootload_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bootload_data_send(MAVLINK_COMM_1 , packet1.bootload_data );
    mavlink_msg_bootload_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BOOTLOAD_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BOOTLOAD_DATA) != NULL);
#endif
}

static void mavlink_test_gimbal_additional_attitude(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GIMBAL_ADDITIONAL_ATTITUDE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gimbal_additional_attitude_t packet_in = {
        963497464,45.0,73.0,101.0
    };
    mavlink_gimbal_additional_attitude_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.roll_relative = packet_in.roll_relative;
        packet1.pitch_relative = packet_in.pitch_relative;
        packet1.yaw_global = packet_in.yaw_global;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GIMBAL_ADDITIONAL_ATTITUDE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GIMBAL_ADDITIONAL_ATTITUDE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_additional_attitude_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gimbal_additional_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_additional_attitude_pack(system_id, component_id, &msg , packet1.time_boot_ms , packet1.roll_relative , packet1.pitch_relative , packet1.yaw_global );
    mavlink_msg_gimbal_additional_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_additional_attitude_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_boot_ms , packet1.roll_relative , packet1.pitch_relative , packet1.yaw_global );
    mavlink_msg_gimbal_additional_attitude_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gimbal_additional_attitude_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_additional_attitude_send(MAVLINK_COMM_1 , packet1.time_boot_ms , packet1.roll_relative , packet1.pitch_relative , packet1.yaw_global );
    mavlink_msg_gimbal_additional_attitude_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GIMBAL_ADDITIONAL_ATTITUDE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GIMBAL_ADDITIONAL_ATTITUDE) != NULL);
#endif
}

static void mavlink_test_update_status_feedback(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_UPDATE_STATUS_FEEDBACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_update_status_feedback_t packet_in = {
        5,72,139,206,17
    };
    mavlink_update_status_feedback_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.module_name = packet_in.module_name;
        packet1.update_status = packet_in.update_status;
        packet1.progress = packet_in.progress;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_UPDATE_STATUS_FEEDBACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_UPDATE_STATUS_FEEDBACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_update_status_feedback_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_update_status_feedback_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_update_status_feedback_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.module_name , packet1.update_status , packet1.progress );
    mavlink_msg_update_status_feedback_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_update_status_feedback_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.module_name , packet1.update_status , packet1.progress );
    mavlink_msg_update_status_feedback_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_update_status_feedback_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_update_status_feedback_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.module_name , packet1.update_status , packet1.progress );
    mavlink_msg_update_status_feedback_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("UPDATE_STATUS_FEEDBACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_UPDATE_STATUS_FEEDBACK) != NULL);
#endif
}

static void mavlink_test_mav_rc_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MAV_RC_CMD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mav_rc_cmd_t packet_in = {
        5,{ 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69 }
    };
    mavlink_mav_rc_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.command = packet_in.command;
        
        mav_array_memcpy(packet1.params, packet_in.params, sizeof(uint8_t)*254);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MAV_RC_CMD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MAV_RC_CMD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mav_rc_cmd_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mav_rc_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mav_rc_cmd_pack(system_id, component_id, &msg , packet1.command , packet1.params );
    mavlink_msg_mav_rc_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mav_rc_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.command , packet1.params );
    mavlink_msg_mav_rc_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mav_rc_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mav_rc_cmd_send(MAVLINK_COMM_1 , packet1.command , packet1.params );
    mavlink_msg_mav_rc_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MAV_RC_CMD") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MAV_RC_CMD) != NULL);
#endif
}

static void mavlink_test_mav_rc_cmd_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MAV_RC_CMD_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mav_rc_cmd_ack_t packet_in = {
        5,72,{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135 }
    };
    mavlink_mav_rc_cmd_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.command = packet_in.command;
        packet1.code = packet_in.code;
        
        mav_array_memcpy(packet1.params, packet_in.params, sizeof(uint8_t)*253);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MAV_RC_CMD_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MAV_RC_CMD_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mav_rc_cmd_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mav_rc_cmd_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mav_rc_cmd_ack_pack(system_id, component_id, &msg , packet1.command , packet1.code , packet1.params );
    mavlink_msg_mav_rc_cmd_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mav_rc_cmd_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.command , packet1.code , packet1.params );
    mavlink_msg_mav_rc_cmd_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mav_rc_cmd_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mav_rc_cmd_ack_send(MAVLINK_COMM_1 , packet1.command , packet1.code , packet1.params );
    mavlink_msg_mav_rc_cmd_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MAV_RC_CMD_ACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MAV_RC_CMD_ACK) != NULL);
#endif
}

static void mavlink_test_bat_general_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BAT_GENERAL_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_bat_general_info_t packet_in = {
        963497464,17443,17547,17651,17755,17859,17963,{ 18067, 18068, 18069, 18070, 18071, 18072, 18073, 18074, 18075, 18076, 18077, 18078 },19315,19419,{ 19523, 19524, 19525, 19526, 19527, 19528, 19529, 19530, 19531, 19532, 19533, 19534 },{ 20771, 20772, 20773, 20774, 20775, 20776, 20777, 20778, 20779, 20780, 20781, 20782 },22019,22123,22227,171,238,49
    };
    mavlink_bat_general_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.alert = packet_in.alert;
        packet1.capacity = packet_in.capacity;
        packet1.remCap = packet_in.remCap;
        packet1.remSOC = packet_in.remSOC;
        packet1.temperature = packet_in.temperature;
        packet1.packVolt = packet_in.packVolt;
        packet1.allVolt = packet_in.allVolt;
        packet1.health = packet_in.health;
        packet1.cycle = packet_in.cycle;
        packet1.maxChargeCurrent = packet_in.maxChargeCurrent;
        packet1.maxDishargeCurrent = packet_in.maxDishargeCurrent;
        packet1.numOfOverCharge = packet_in.numOfOverCharge;
        packet1.onOff = packet_in.onOff;
        packet1.maxTem = packet_in.maxTem;
        packet1.minTem = packet_in.minTem;
        
        mav_array_memcpy(packet1.cellnVolt, packet_in.cellnVolt, sizeof(uint16_t)*12);
        mav_array_memcpy(packet1.maxVn, packet_in.maxVn, sizeof(uint16_t)*12);
        mav_array_memcpy(packet1.minVn, packet_in.minVn, sizeof(uint16_t)*12);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BAT_GENERAL_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BAT_GENERAL_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_general_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_bat_general_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_general_info_pack(system_id, component_id, &msg , packet1.capacity , packet1.remCap , packet1.remSOC , packet1.temperature , packet1.packVolt , packet1.allVolt , packet1.cellnVolt , packet1.health , packet1.alert , packet1.onOff , packet1.cycle , packet1.maxVn , packet1.minVn , packet1.maxTem , packet1.minTem , packet1.maxChargeCurrent , packet1.maxDishargeCurrent , packet1.numOfOverCharge );
    mavlink_msg_bat_general_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_general_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.capacity , packet1.remCap , packet1.remSOC , packet1.temperature , packet1.packVolt , packet1.allVolt , packet1.cellnVolt , packet1.health , packet1.alert , packet1.onOff , packet1.cycle , packet1.maxVn , packet1.minVn , packet1.maxTem , packet1.minTem , packet1.maxChargeCurrent , packet1.maxDishargeCurrent , packet1.numOfOverCharge );
    mavlink_msg_bat_general_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_bat_general_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_general_info_send(MAVLINK_COMM_1 , packet1.capacity , packet1.remCap , packet1.remSOC , packet1.temperature , packet1.packVolt , packet1.allVolt , packet1.cellnVolt , packet1.health , packet1.alert , packet1.onOff , packet1.cycle , packet1.maxVn , packet1.minVn , packet1.maxTem , packet1.minTem , packet1.maxChargeCurrent , packet1.maxDishargeCurrent , packet1.numOfOverCharge );
    mavlink_msg_bat_general_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BAT_GENERAL_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BAT_GENERAL_INFO) != NULL);
#endif
}

static void mavlink_test_bat_common_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BAT_COMMON_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_bat_common_info_t packet_in = {
        963497464,17443,17547,17651,17755,{ 17859, 17860, 17861, 17862, 17863, 17864, 17865, 17866, 17867, 17868, 17869, 17870 },19107,247
    };
    mavlink_bat_common_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.alert = packet_in.alert;
        packet1.remCap = packet_in.remCap;
        packet1.remSOC = packet_in.remSOC;
        packet1.temperature = packet_in.temperature;
        packet1.packVolt = packet_in.packVolt;
        packet1.current = packet_in.current;
        packet1.onOff = packet_in.onOff;
        
        mav_array_memcpy(packet1.cellnVolt, packet_in.cellnVolt, sizeof(uint16_t)*12);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BAT_COMMON_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BAT_COMMON_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_common_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_bat_common_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_common_info_pack(system_id, component_id, &msg , packet1.remCap , packet1.remSOC , packet1.temperature , packet1.packVolt , packet1.cellnVolt , packet1.current , packet1.alert , packet1.onOff );
    mavlink_msg_bat_common_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_common_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.remCap , packet1.remSOC , packet1.temperature , packet1.packVolt , packet1.cellnVolt , packet1.current , packet1.alert , packet1.onOff );
    mavlink_msg_bat_common_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_bat_common_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_common_info_send(MAVLINK_COMM_1 , packet1.remCap , packet1.remSOC , packet1.temperature , packet1.packVolt , packet1.cellnVolt , packet1.current , packet1.alert , packet1.onOff );
    mavlink_msg_bat_common_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BAT_COMMON_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BAT_COMMON_INFO) != NULL);
#endif
}

static void mavlink_test_bat_const_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BAT_CONST_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_bat_const_info_t packet_in = {
        963497464,963497672,963497880,963498088,18067,{ 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197 },{ 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187 },252
    };
    mavlink_bat_const_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.firmwareVersion = packet_in.firmwareVersion;
        packet1.bootloaderVersion = packet_in.bootloaderVersion;
        packet1.hardwareVersion = packet_in.hardwareVersion;
        packet1.firmwareSize = packet_in.firmwareSize;
        packet1.designCap = packet_in.designCap;
        packet1.nCell = packet_in.nCell;
        
        mav_array_memcpy(packet1.MCUType, packet_in.MCUType, sizeof(uint8_t)*11);
        mav_array_memcpy(packet1.companyOfBat, packet_in.companyOfBat, sizeof(uint8_t)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BAT_CONST_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BAT_CONST_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_const_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_bat_const_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_const_info_pack(system_id, component_id, &msg , packet1.firmwareVersion , packet1.bootloaderVersion , packet1.hardwareVersion , packet1.firmwareSize , packet1.MCUType , packet1.companyOfBat , packet1.nCell , packet1.designCap );
    mavlink_msg_bat_const_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_const_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.firmwareVersion , packet1.bootloaderVersion , packet1.hardwareVersion , packet1.firmwareSize , packet1.MCUType , packet1.companyOfBat , packet1.nCell , packet1.designCap );
    mavlink_msg_bat_const_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_bat_const_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_const_info_send(MAVLINK_COMM_1 , packet1.firmwareVersion , packet1.bootloaderVersion , packet1.hardwareVersion , packet1.firmwareSize , packet1.MCUType , packet1.companyOfBat , packet1.nCell , packet1.designCap );
    mavlink_msg_bat_const_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BAT_CONST_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BAT_CONST_INFO) != NULL);
#endif
}

static void mavlink_test_bat_production_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BAT_PRODUCTION_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_bat_production_info_t packet_in = {
        { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },{ 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178 }
    };
    mavlink_bat_production_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.productionTime, packet_in.productionTime, sizeof(uint8_t)*10);
        mav_array_memcpy(packet1.keyOfBat, packet_in.keyOfBat, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BAT_PRODUCTION_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BAT_PRODUCTION_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_production_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_bat_production_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_production_info_pack(system_id, component_id, &msg , packet1.productionTime , packet1.keyOfBat );
    mavlink_msg_bat_production_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_production_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.productionTime , packet1.keyOfBat );
    mavlink_msg_bat_production_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_bat_production_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bat_production_info_send(MAVLINK_COMM_1 , packet1.productionTime , packet1.keyOfBat );
    mavlink_msg_bat_production_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BAT_PRODUCTION_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BAT_PRODUCTION_INFO) != NULL);
#endif
}

static void mavlink_test_goertek(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_visual_tracking(system_id, component_id, last_msg);
    mavlink_test_task_up_mis(system_id, component_id, last_msg);
    mavlink_test_task_down_mis(system_id, component_id, last_msg);
    mavlink_test_task_request_list(system_id, component_id, last_msg);
    mavlink_test_task_ack(system_id, component_id, last_msg);
    mavlink_test_task_state_feedback(system_id, component_id, last_msg);
    mavlink_test_vision_modules_versions(system_id, component_id, last_msg);
    mavlink_test_estimator_mode_additions(system_id, component_id, last_msg);
    mavlink_test_no_fly_zone_unlocking(system_id, component_id, last_msg);
    mavlink_test_yuneec_optical_flow_rad(system_id, component_id, last_msg);
    mavlink_test_nfz_unlock_status(system_id, component_id, last_msg);
    mavlink_test_task_mission_item(system_id, component_id, last_msg);
    mavlink_test_task_mission_down_mis(system_id, component_id, last_msg);
    mavlink_test_ync_param_ext_value(system_id, component_id, last_msg);
    mavlink_test_ync_param_ext_set(system_id, component_id, last_msg);
    mavlink_test_ync_param_ext_ack(system_id, component_id, last_msg);
    mavlink_test_ync_param_ext_request_read(system_id, component_id, last_msg);
    mavlink_test_ync_param_ext_request_list(system_id, component_id, last_msg);
    mavlink_test_exposure_event_request(system_id, component_id, last_msg);
    mavlink_test_exposure_event_ack(system_id, component_id, last_msg);
    mavlink_test_task_mission_ack(system_id, component_id, last_msg);
    mavlink_test_task_mission_state(system_id, component_id, last_msg);
    mavlink_test_task_mission_state_request(system_id, component_id, last_msg);
    mavlink_test_task_mission_manage(system_id, component_id, last_msg);
    mavlink_test_task_mission_request(system_id, component_id, last_msg);
    mavlink_test_task_mission_waypoint_reached(system_id, component_id, last_msg);
    mavlink_test_camera_notification_panorama(system_id, component_id, last_msg);
    mavlink_test_mission_action(system_id, component_id, last_msg);
    mavlink_test_mission_action_ack(system_id, component_id, last_msg);
    mavlink_test_component_version_info(system_id, component_id, last_msg);
    mavlink_test_gimbal_control(system_id, component_id, last_msg);
    mavlink_test_gimbal_control_standard(system_id, component_id, last_msg);
    mavlink_test_gimbal_debugdata(system_id, component_id, last_msg);
    mavlink_test_bootload_data(system_id, component_id, last_msg);
    mavlink_test_gimbal_additional_attitude(system_id, component_id, last_msg);
    mavlink_test_update_status_feedback(system_id, component_id, last_msg);
    mavlink_test_mav_rc_cmd(system_id, component_id, last_msg);
    mavlink_test_mav_rc_cmd_ack(system_id, component_id, last_msg);
    mavlink_test_bat_general_info(system_id, component_id, last_msg);
    mavlink_test_bat_common_info(system_id, component_id, last_msg);
    mavlink_test_bat_const_info(system_id, component_id, last_msg);
    mavlink_test_bat_production_info(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // GOERTEK_TESTSUITE_H
