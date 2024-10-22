/*
 * Line_Follower.h
 *
 *  Created on: 18 paź 2024
 *      Author: Szymon
 */

#ifndef INC_LINE_FOLLOWER_H_
#define INC_LINE_FOLLOWER_H_

typedef struct
{
	float Kp;
	float Kd;

	int Base_speed_R;
	int Base_speed_L;
	int Max_speed_R;
	int Max_speed_L;

	int Sharp_bend_speed_right;
	int Sharp_bend_speed_left;
	int Bend_speed_right;
	int Bend_speed_left;

	float battery_voltage;
	uint16_t Adc_Value;
	float Speed_level;
	float Speed_offset;

} LineFollower_t;

#endif /* INC_LINE_FOLLOWER_H_ */
