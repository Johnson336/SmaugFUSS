/****************************************************************************
 *                   ^     +----- |  / ^     ^ |     | +-\                  *
 *                  / \    |      | /  |\   /| |     | |  \                 *
 *                 /   \   +---   |<   | \ / | |     | |  |                 *
 *                /-----\  |      | \  |  v  | |     | |  /                 *
 *               /       \ |      |  \ |     | +-----+ +-/                  *
 ****************************************************************************
 * AFKMud Copyright 1997-2003 by Roger Libiez (Samson),                     *
 * Levi Beckerson (Whir), Michael Ward (Tarl), Erik Wolfe (Dwip),           *
 * Cameron Carroll (Cam), Cyberfox, Karangi, Rathian, Raine, and Adjani.    *
 * All Rights Reserved.                                                     *
 *                                                                          *
 * Original SMAUG 1.4a written by Thoric (Derek Snider) with Altrag,        *
 * Blodkai, Haus, Narn, Scryn, Swordbearer, Tricops, Gorog, Rennard,        *
 * Grishnakh, Fireblade, and Nivek.                                         *
 *                                                                          *
 * Original MERC 2.1 code by Hatchet, Furey, and Kahn.                      *
 *                                                                          *
 * Original DikuMUD code by: Hans Staerfeldt, Katja Nyboe, Tom Madsen,      *
 * Michael Seifert, and Sebastian Hammer.                                   *
 *****************************************************************************
 *			         Hotboot support headers                          *
 ****************************************************************************/

#ifndef CH
#define CH(d)			((d)->original ? (d)->original : (d)->character)
#endif /* 
        */

#define HOTBOOT_FILE SYSTEM_DIR "reescribir.datos"  /* for hotboots */
#define EXE_FILE "phantasiemIII"
#define HOTBOOT_DIR "inicio/"   /* For storing objects across hotboots */
#define MOB_FILE	"monstruos.datos"  /* For storing mobs across hotboots */

/* warmboot code */
void hotboot_recover( void );

void load_world( void );

DECLARE_DO_FUN( do_hotboot ); /* Hotboot command - Samson 3-31-01 */
