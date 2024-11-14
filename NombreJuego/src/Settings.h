#pragma once

#include <string>
#include <filesystem>

const float GREEN_POSITION_X					=	0.40f;
const float RED_POSITION_X						=	0.45f;
const float YELLOW_POSITION_X					=	0.50f;
const float BLUE_POSITION_X						=	0.55f;
const float ORANGE_POSITION_X					=	0.60f;
const float BUTTON_POSITION_Y					=	0.95f;
const float START_NOTE_POSITION_Y				=	0.0f;
const float END_NOTE_POSITION_Y					=	0.95f;
const float NOTE_DURATION						=	3.0f;
const int POINT_PUBLIC							=	2;
const int INDEX_GREEN_BUTTON					=	0;
const int INDEX_RED_BUTTON						=	1;
const int INDEX_YELLOW_BUTTON					=	2;
const int INDEX_BLUE_BUTTON						=	3;
const int INDEX_ORANGE_BUTTON					=	4;
const int SHAKE_STRAKE							=	10;
const int MAX_PUBLIC_SCORE						=	100;
const int MIN_PUBLIC_SCORE						=	0;
const int POINTS_PER_NOTE						=	10;

const std::string CURRENT_PATH					=	std::filesystem::current_path().string();

const std::string TEXTURE_PATH					=	"\\res\\textures\\";
const std::string SONG_PATH						=	"\\res\\songs\\";
const std::string METRONOME_PATH				=	"metronomo.mp3";
const std::string PUBLIC_HAPPY_PATH				=	"public_happy.mp3";
const std::string PUBLIC_ANGRY_PATH				=	"public_angry.mp3";
const std::string BUFFER_BAD_NOTE_1				=	"bad_note1.mp3";
const std::string KEY_UP						=	"arrow_up_light.png";
const std::string KEY_DOWN						=	"arrow_down_light.png";
const std::string KEY_LEFT						=	"arrow_left_light.png";
const std::string KEY_RIGHT						=	"arrow_right_light.png";
const std::string KEY_Q							=	"q_light.png";
const std::string KEY_W							=	"w_light.png";
const std::string KEY_E							=	"e_light.png";
const std::string KEY_R							=	"r_light.png";
const std::string KEY_T							=	"t_light.png";
const std::string BUFFER_BAD_NOTE_2				=	"bad_note2.mp3";
const std::string BUFFER_BAD_NOTE_3				=	"bad_note3.mp3";
const std::string BUFFER_BAD_NOTE_4				=	"bad_note4.mp3";
const std::string BUFFER_BAD_NOTE_5				=	"bad_note5.mp3";
const std::string BUFFER_MENU_UP				=	"menu_up.mp3";
const std::string BUFFER_MENU_DOWN				=	"menu_down.mp3";
const std::string FONT_PATH						=	"res\\fonts\\letra.ttf";
const std::string SPINNER_TEXTURE				=	"spinner.png";
const std::string LABEL_A_TEXTURE				=	"label_A.png";
const std::string LABEL_B_TEXTURE				=	"label_B.png";
const std::string LABEL_C_TEXTURE				=	"label_C.png";
const std::string BACKGROUND_TEXTURE			=	"background.png";
const std::string BACKGROUND_TEXTURE_2			=	"background_2.png";
const std::string LINKEDIN_TEXTURE				=	"linkedin.png";
const std::string GIT_TEXTURE					=	"git.png";
const std::string FRETBOARD_TEXTURE				=	"fretboard.png";

const std::string NOTE_GREEN_TEXTURE			=	"note_green.png";
const std::string NOTE_RED_TEXTURE				=	"note_red.png";
const std::string NOTE_YELLOW_TEXTURE			=	"note_yellow.png";
const std::string NOTE_BLUE_TEXTURE				=	"note_blue.png";
const std::string NOTE_ORANGE_TEXTURE			=	"note_orange.png";

const std::string BUTTON_GREEN_TEXTURE			=	"button_green.png";
const std::string BUTTON_RED_TEXTURE			=	"button_red.png";
const std::string BUTTON_YELLOW_TEXTURE			=	"button_yellow.png";
const std::string BUTTON_BLUE_TEXTURE			=	"button_blue.png";
const std::string BUTTON_ORANGE_TEXTURE			=	"button_orange.png";
													
const std::string BUTTON_PRESS_GREEN_TEXTURE	=	"button_press_green.png";
const std::string BUTTON_PRESS_RED_TEXTURE		=	"button_press_red.png";
const std::string BUTTON_PRESS_YELLOW_TEXTURE	=	"button_press_yellow.png";
const std::string BUTTON_PRESS_BLUE_TEXTURE		=	"button_press_blue.png";
const std::string BUTTON_PRESS_ORANGE_TEXTURE	=	"button_press_orange.png";

const std::string ARROW_TEXTURE					=	"arrow.png";
const std::string POWER_UP_ONE_TEXTURE			=	"PowerUp_1.png";
const std::string POWER_UP_TWO_TEXTURE			=	"PowerUp_2.png";
const std::string ROCK_METER_TEXTURE			=	"rock_meter.png";
const std::string TRACK_TEXTURE					=	"track.png";
const std::string DISC_TEXTURE					=	"disc.png";

