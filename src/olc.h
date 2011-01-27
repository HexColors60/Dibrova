/************************************************************************
 * OasisOLC - olc.h						v1.5	*
 *									*
 * Copyright 1996 Harvey Gilpin.					*
 ************************************************************************/

/*
 * If you don't want a short explanation of each field in your zone files,
 * change the number below to a 0 instead of a 1.
 */
#if 0
#define ZEDIT_HELP_IN_FILE
#endif

/*
 * If you want to clear the screen before certain Oasis menus, set to 1.
 */
#if 0
#define CLEAR_SCREEN	1
#endif

/*
 * Set this to 1 to enable MobProg support.
 */
#if 0
#define OASIS_MPROG	1
#endif

/*
 * Macros, defines, structs and globals for the OLC suite.
 */

#define NUM_ROOM_FLAGS 		29
#define NUM_ROOM_SECTORS	18

#define NUM_MOB_FLAGS		27
#define NUM_AFF_FLAGS	    102 
#define NUM_ATTACK_TYPES	19

#define NUM_ITEM_TYPES		35
#define NUM_ITEM_FLAGS		41
#define NUM_ITEM_WEARS 	    22
#define NUM_APPLIES		    30
#define NUM_LIQ_TYPES 		23
#define NUM_POSITIONS		18
#define NUM_SPELLS          183

#define NUM_GENDERS		    3
#define NUM_SHOP_FLAGS 		2
#define NUM_TRADERS 		22

/*
 * Define this to how many MobProg scripts you have.
 */
#define NUM_PROGS		12

/* #define LVL_BUILDER		LVL_BUILDER */

/*
 * Utilities exported from olc.c.
 */
void strip_string(char *);
void cleanup_olc(struct descriptor_data *d, byte cleanup_type);
void get_char_cols(struct char_data *ch);
void olc_add_to_save_list(int zone, byte type);
void olc_remove_from_save_list(int zone, byte type);

/*
 * OLC structures.
 */

struct olc_data {
  int mode;
  int zone_num;
  int number;
  int owner;
  int value;
  int total_mprogs;
  struct char_data *mob;
  struct room_data *room;
  struct obj_data *obj;
  struct zone_data *zone;
  struct shop_data *shop;
  struct extra_descr_data *desc;
  struct aq_data *quest;
#if defined(OASIS_MPROG)
  struct mob_prog_data *mprog;
  struct mob_prog_data *mprogl;
#endif
  struct trig_data *trig;
  int script_mode;
  int trigger_position;
  int item_type;
  struct trig_proto_list *script;
  char *storage; /* for holding commands etc.. */
};

struct olc_save_info {
  int zone;
  char type;
  struct olc_save_info *next;
};

/*
 * Exported globals.
 */
#ifdef _OASIS_OLC_
char *nrm, *grn, *cyn, *yel, *red;
struct olc_save_info *olc_save_list = NULL;
#else
extern char *nrm, *grn, *cyn, *yel, *red;
extern struct olc_save_info *olc_save_list;
#endif

/*
 * Descriptor access macros.
 */
#define OLC_MODE(d) 	((d)->olc->mode)	/* Parse input mode.	*/
#define OLC_NUM(d) 	((d)->olc->number)	/* Room/Obj VNUM.	*/
#define OLC_VAL(d) 	((d)->olc->value)	/* Scratch variable.	*/
#define OLC_ZNUM(d) 	((d)->olc->zone_num)	/* Real zone number.	*/
#define OLC_ROOM(d) 	((d)->olc->room)	/* Room structure.	*/
#define OLC_OBJ(d) 	((d)->olc->obj)		/* Object structure.	*/
#define OLC_ZONE(d)     ((d)->olc->zone)	/* Zone structure.	*/
#define OLC_MOB(d)	((d)->olc->mob)		/* Mob structure.	*/
#define OLC_SHOP(d) 	((d)->olc->shop)	/* Shop structure.	*/
#define OLC_DESC(d) 	((d)->olc->desc)	/* Extra description.	*/
#define OLC_QUEST(d)    ((d)->olc->quest)       /* Quest structure      */
#ifdef OASIS_MPROG
#define OLC_MPROG(d)	((d)->olc->mprog)	/* Temporary MobProg.	*/
#define OLC_MPROGL(d)	((d)->olc->mprogl)	/* MobProg list.	*/
#define OLC_MTOTAL(d)	((d)->olc->total_mprogs) Total mprog number.	*/
#endif
#define OLC_TRIG(d)     ((d)->olc->trig)        /* Trigger structure.   */
#define OLC_STORAGE(d)  ((d)->olc->storage)    /* For command storage  */

/*
 * Other macros.
 */
#define OLC_EXIT(d)	(OLC_ROOM(d)->dir_option[OLC_VAL(d)])
#define GET_OLC_ZONE(c)	((c)->player_specials->saved.tier)

/* Formulae for autostatting */
#define SUGGEST_EXP(m)  (uint)(MIN((pow(GET_LEVEL(m)*2, 2.55)*.8), 4500000))
#define SUGGEST_AC(m)   (-GET_LEVEL(m)+100)
#define SUGGEST_HR(m)   (int)(pow(GET_LEVEL(m)/(float)120, 1.4)*100)

/*
 * Cleanup types.
 */
#define CLEANUP_ALL		(byte)	1	/* Free the whole lot.	*/
#define CLEANUP_STRUCTS 	(byte)	2	/* Don't free strings.	*/

/*
 * Add/Remove save list types.
 */
#define OLC_SAVE_ROOM		(byte)	0
#define OLC_SAVE_OBJ		(byte)	1
#define OLC_SAVE_ZONE		(byte)	2
#define OLC_SAVE_MOB		(byte)	3
#define OLC_SAVE_SHOP		(byte)	4
#define OLC_SAVE_QUEST		(byte)  5

/*
 * Submodes of OEDIT connectedness.
 */
#define OEDIT_MAIN_MENU              	1
#define OEDIT_EDIT_NAMELIST          	2
#define OEDIT_SHORTDESC              	3
#define OEDIT_LONGDESC               	4
#define OEDIT_ACTDESC                	5
#define OEDIT_TYPE                   	6
#define OEDIT_EXTRAS                 	7
#define OEDIT_WEAR                  	8
#define OEDIT_WEIGHT                	9
#define OEDIT_COST                  	10
#define OEDIT_COSTPERDAY            	11
#define OEDIT_TIMER                 	12
#define OEDIT_VALUE_1               	13
#define OEDIT_VALUE_2               	14
#define OEDIT_VALUE_3               	15
#define OEDIT_VALUE_4               	16
#define OEDIT_APPLY                 	17
#define OEDIT_APPLYMOD              	18
#define OEDIT_EXTRADESC_KEY         	19
#define OEDIT_CONFIRM_SAVEDB        	20
#define OEDIT_CONFIRM_SAVESTRING    	21
#define OEDIT_PROMPT_APPLY          	22
#define OEDIT_EXTRADESC_DESCRIPTION 	23
#define OEDIT_EXTRADESC_MENU        	24
#define OEDIT_LEVEL                 	25
#define OEDIT_MINLEVEL                 	26
#define OEDIT_PERSISTENT_SPELL        	27
#define OEDIT_PERSISTENT_SPELL_EXTRA  	28
#define OEDIT_AFFECTION                 29
#define OEDIT_CLAN                      30
#define OEDIT_PLAYER                    31
#define OEDIT_VAMP_WEAR                 32
#define OEDIT_TITAN_WEAR                33
#define OEDIT_SAINT_WEAR                34
#define OEDIT_DEMON_WEAR                35

/*
 * Submodes of REDIT connectedness.
 */
#define REDIT_MAIN_MENU 		1
#define REDIT_NAME 			2
#define REDIT_DESC 			3
#define REDIT_FLAGS 			4
#define REDIT_SECTOR 			5
#define REDIT_EXIT_MENU 		6
#define REDIT_CONFIRM_SAVEDB 		7
#define REDIT_CONFIRM_SAVESTRING 	8
#define REDIT_EXIT_NUMBER 		9
#define REDIT_EXIT_DESCRIPTION 		10
#define REDIT_EXIT_KEYWORD 		11
#define REDIT_EXIT_KEY 			12
#define REDIT_EXIT_DOORFLAGS 		13
#define REDIT_EXTRADESC_MENU 		14
#define REDIT_EXTRADESC_KEY 		15
#define REDIT_EXTRADESC_DESCRIPTION 	16

/*
 * Submodes of ZEDIT connectedness.
 */
#define ZEDIT_MAIN_MENU              	0
#define ZEDIT_DELETE_ENTRY		1
#define ZEDIT_NEW_ENTRY			2
#define ZEDIT_CHANGE_ENTRY		3
#define ZEDIT_COMMAND_TYPE		4
#define ZEDIT_IF_FLAG			5
#define ZEDIT_ARG1			6
#define ZEDIT_ARG2			7
#define ZEDIT_ARG3			8
#define ZEDIT_ARG4			9
#define ZEDIT_ZONE_NAME			10
#define ZEDIT_ZONE_LIFE			11
#define ZEDIT_ZONE_TOP			12
#define ZEDIT_ZONE_RESET		13
#define ZEDIT_CONFIRM_SAVESTRING	14
#define ZEDIT_DEVELOPMENT		15
#define ZEDIT_ZONE_OWNER                16
#define ZEDIT_SARG1			20
#define ZEDIT_SARG2			21

/*
 * Submodes of MEDIT connectedness.
 */
#define MEDIT_MAIN_MENU              	0
#define MEDIT_ALIAS			1
#define MEDIT_S_DESC			2
#define MEDIT_L_DESC			3
#define MEDIT_D_DESC			4
#define MEDIT_NPC_FLAGS			5
#define MEDIT_AFF_FLAGS			6
#define MEDIT_CONFIRM_SAVESTRING	7
#define MEDIT_STATS_MENU                8

/*
 * Numerical responses.
 */
#define MEDIT_NUMERICAL_RESPONSE	10
#define MEDIT_SEX			11
#define MEDIT_HITROLL			12
#define MEDIT_DAMROLL			13
#define MEDIT_NDD			14
#define MEDIT_SDD			15
#define MEDIT_NUM_HP_DICE		16
#define MEDIT_SIZE_HP_DICE		17
#define MEDIT_ADD_HP			18
#define MEDIT_AC			19
#define MEDIT_EXP			20
#define MEDIT_GOLD			21
#define MEDIT_POS			22
#define MEDIT_DEFAULT_POS		23
#define MEDIT_ATTACK			24
#define MEDIT_LEVEL			25
#define MEDIT_ALIGNMENT			26
#define MEDIT_CLASS                     27
#define MEDIT_STR                       28
#define MEDIT_DEX                       29
#define MEDIT_CON                       30
#define MEDIT_INT                       31
#define MEDIT_WIS                       32
#define MEDIT_CHA                       33
#define MEDIT_LUCK                      34
#define MEDIT_RACE                      35
#define MEDIT_ABILITIES					36
#define MEDIT_ABIL_SKILLS				37
#define MEDIT_ABIL_SPELLS				38
#define MEDIT_ABIL_CHANTS				39
#define MEDIT_ABIL_PRAYERS				40
#define MEDIT_ABIL_PRAYER1				41
#define MEDIT_ABIL_PRAYER2				42
#define MEDIT_ABIL_PRAYER3				43
#define MEDIT_ABIL_PRAYER4				44
#define MEDIT_ABIL_PRAYER5				45
#define MEDIT_ABIL_CHANT1				46
#define MEDIT_ABIL_CHANT2				47
#define MEDIT_ABIL_CHANT3				48
#define MEDIT_ABIL_CHANT4				49
#define MEDIT_ABIL_CHANT5				50
#define MEDIT_ABIL_SPELL1				51
#define MEDIT_ABIL_SPELL2				52
#define MEDIT_ABIL_SPELL3				53
#define MEDIT_ABIL_SPELL4				54
#define MEDIT_ABIL_SPELL5				55
#define MEDIT_ABIL_SKILL1				56
#define MEDIT_ABIL_SKILL2				57
#define MEDIT_ABIL_SKILL3				58
#define MEDIT_ABIL_SKILL4				59
#define MEDIT_ABIL_SKILL5				60
#define MEDIT_ABIL_PALADIN				61
#define MEDIT_ABIL_DARK_KNIGHT			62
#define MEDIT_ABIL_MONK					63
#define MEDIT_MOUNTTYPE					64

#if defined(OASIS_MPROG)
#define MEDIT_MPROG                     28
#define MEDIT_CHANGE_MPROG              29
#define MEDIT_MPROG_COMLIST             30
#define MEDIT_MPROG_ARGS                31
#define MEDIT_MPROG_TYPE                32
#define MEDIT_PURGE_MPROG               33
#endif

/*
 * Submodes of SEDIT connectedness.
 */
#define SEDIT_MAIN_MENU              	0
#define SEDIT_CONFIRM_SAVESTRING	1
#define SEDIT_NOITEM1			2
#define SEDIT_NOITEM2			3
#define SEDIT_NOCASH1			4
#define SEDIT_NOCASH2			5
#define SEDIT_NOBUY			6
#define SEDIT_BUY			7
#define SEDIT_SELL			8
#define SEDIT_PRODUCTS_MENU		11
#define SEDIT_ROOMS_MENU		12
#define SEDIT_NAMELIST_MENU		13
#define SEDIT_NAMELIST			14
/*
 * Numerical responses.
 */
#define SEDIT_NUMERICAL_RESPONSE	20
#define SEDIT_OPEN1			21
#define SEDIT_OPEN2			22
#define SEDIT_CLOSE1			23
#define SEDIT_CLOSE2			24
#define SEDIT_KEEPER			25
#define SEDIT_BUY_PROFIT		26
#define SEDIT_SELL_PROFIT		27
#define SEDIT_TYPE_MENU			29
#define SEDIT_DELETE_TYPE		30
#define SEDIT_DELETE_PRODUCT		31
#define SEDIT_NEW_PRODUCT		32
#define SEDIT_DELETE_ROOM		33
#define SEDIT_NEW_ROOM			34
#define SEDIT_SHOP_FLAGS		35
#define SEDIT_NOTRADE			36

/*. Quest editor .*/
#define QEDIT_MAIN_MENU                 0
#define QEDIT_CONFIRM_SAVESTRING        1
#define QEDIT_NAME                      2
#define QEDIT_DESC                      3
#define QEDIT_INFO			4
#define QEDIT_ENDING			5
#define QEDIT_QUESTMASTER               6
#define QEDIT_TYPE                      7
#define QEDIT_FLAGS                     8
#define QEDIT_TARGET                    9
#define QEDIT_EXP                       10
#define QEDIT_NEXT			11
#define QEDIT_VALUE_0			12
#define QEDIT_VALUE_1			13
#define QEDIT_VALUE_2			14
#define QEDIT_VALUE_3			15
#define QEDIT_GOLD			16
#define QEDIT_QP			17
#define QEDIT_OBJ_NUM			18
#define QEDIT_MAXLEV			19
#define QEDIT_MINLEV			20

/*
 * Limit information.
 */
#define MAX_ROOM_NAME	75
#define MAX_MOB_NAME	50
#define MAX_OBJ_NAME	50
#define MAX_QUEST_NAME	50
#define MAX_QUEST_INFO  1024
#define MAX_QUEST_ENDING 1024
#define MAX_ROOM_DESC	1024
#define MAX_EXIT_DESC	256
#define MAX_EXTRA_DESC  512
#define MAX_MOB_DESC	512
#define MAX_OBJ_DESC	512
