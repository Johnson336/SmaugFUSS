#!@ENV@ make -f

#                     R E A L M S    O F    D E S P A I R  !
#   ___________________________________________________________________________
#  //            /                                                            \\
# [|_____________\   ********   *        *   ********   *        *   *******   |]
# [|   \\._.//   /  **********  **      **  **********  **      **  *********  |]
# [|   (0...0)   \  **********  ***    ***  **********  ***    ***  *********  |]
# [|    ).:.(    /  ***         ****  ****  ***    ***  ***    ***  ***        |]
# [|    {o o}    \  *********   **********  **********  ***    ***  *** ****   |]
# [|   / ' ' \   /   *********  *** ** ***  **********  ***    ***  ***  ****  |]
# [|-'- /   \ -`-\         ***  ***    ***  ***    ***  ***    ***  ***   ***  |]
# [|   .VxvxV.   /   *********  ***    ***  ***    ***  **********  *********  |]
# [|_____________\  **********  **      **  **      **  **********  *********  |]
# [|             /  *********   *        *  *        *   ********    *******   |]
#  \\____________\____________________________________________________________//
#     |                                                                     |
#     |    --{ [S]imulated [M]edieval [A]dventure Multi[U]ser [G]ame }--    |
#     |_____________________________________________________________________|
#     |                                                                     |
#     |                         -*- Makefile -*-                            |
#     |_____________________________________________________________________|
#    //                                                                     \\
#   [|  SMAUG 1.4 © 1994-1998 Thoric/Altrag/Blodkai/Narn/Haus/Scryn/Rennard  |]
#   [|  Swordbearer/Gorog/Grishnakh/Nivek/Tricops/Fireblade/Edmond/Conran    |]
#   [|                                                                       |]
#   [|  Merc 2.1 Diku Mud improvments © 1992-1993 Michael Chastain, Michael  |]
#   [|  Quan, and Mitchell Tse. Original Diku Mud © 1990-1991 by Sebastian   |]
#   [|  Hammer, Michael Seifert, Hans Henrik St{rfeldt, Tom Madsen, Katja    |]
#   [|  Nyboe. Win32 port Nick Gammon.                                       |]
#   [|                                                                       |]
#   [|  SMAUG 2.0 © 2014-2015 Antonio Cao (@burzumishi)                      |]
#    \\_____________________________________________________________________//

CC = gcc
CPP = cpp
CXX = g++

ARCH = `uname -m`

localedir = $(datadir)/locale
DEFS = -DLOCALEDIR=\"$(localedir)\" @DEFS@

# Uncomment the two lines below if compiling on a Solaris box

# SOLARIS_FLAG = -Dsun -DSYSV
# SOLARIS_LINK = -lnsl -lsocket

CLEANFILES = *~ *.o *.lo *.la *.a *.so smaug.h \
smaug$(EXEEXT) smaug-resolver$(EXEEXT) smaug-httpd$(EXEEXT) stamp-h1

# Build binaries #

# bin/smaug #
bin_PROGRAMS = smaug$(EXEEXT)

# bin/smaug-resolver #
if ENABLE_DNS_RESOLV
bin_PROGRAMS += smaug-resolver$(EXEEXT)
endif

# bin/smaug-httpd #
if HTTPD
bin_PROGRAMS += smaug-httpd$(EXEEXT)
endif

# Build Shared libraries #

# lib/libsmaug-*.la (static libs) #
noinst_LTLIBRARIES = \
libsmaug-act.la libsmaug-player.la libsmaug-mudprog.la \
libsmaug-info.la libsmaug-realm.la

# lib/libsmaug-httpd.la (static lib) #
if HTTPD
noinst_LTLIBRARIES += libsmaug-httpd.la
endif

# lib/libsmaug-dns.la (static lib) #
if ENABLE_DNS_RESOLV
noinst_LTLIBRARIES += libsmaug-dns.la
endif

if IMC
if IMCSMAUG
noinst_LTLIBRARIES += libsmaug-imc.la
endif
endif

if ENABLE_HOTBOOT
noinst_LTLIBRARIES += libsmaug-hotboot.la
endif

# lib/libsmaug-act.so (shared lib) #
libsmaug_act_la_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_act_la_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_act_la_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

libsmaug_act_la_SOURCES = \
act_comm.c act_info.c act_move.c act_obj.c act_wiz.c fight.c misc.c 

# lib/libsmaug-player.so (shared lib) #
libsmaug_player_la_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_player_la_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_player_la_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

libsmaug_player_la_SOURCES = \
player.c polymorph.c update.c save.c ban.c

# lib/libsmaug-mudprog.so (shared lib) #
libsmaug_mudprog_la_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_mudprog_la_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_mudprog_la_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

libsmaug_mudprog_la_SOURCES = \
mud_comm.c mud_prog.c

# lib/libsmaug-info.so (shared lib) #
libsmaug_info_la_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_info_la_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_info_la_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

libsmaug_info_la_SOURCES = \
boards.c comments.c hint.c news.c

# lib/libsmaug-realm.so (shared lib) #
libsmaug_realm_la_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_realm_la_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_realm_la_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

libsmaug_realm_la_SOURCES = \
build.c calendar.c clans.c deity.c house.c planes.c \
liquids.c magic.c makeobjs.c mapper.c mapout.c mpxset.c \
renumber.c reset.c shops.c skills.c special.c \
tables.c track.c variables.c weather.c

if ENABLE_DNS_RESOLV
# libsmaug-dns #

libsmaug_dns_la_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_dns_la_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_dns_la_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

libsmaug_dns_la_SOURCES = dns.c
endif

if IMC
if IMCSMAUG
# lib/libsmaug-imc.so (shared lib) #
libsmaug_imc_la_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_imc_la_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_imc_la_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

libsmaug_imc_la_SOURCES = imc.c
endif
endif

if ENABLE_HOTBOOT
# lib/libsmaug-hotboot.so (shared lib) #
libsmaug_hotboot_la_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_hotboot_la_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_hotboot_la_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

libsmaug_hotboot_la_SOURCES = hotboot.c
endif

# bin/smaug #

smaug_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
smaug_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
smaug_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

smaug_SOURCES = smaug.c \
i18n.c const.c color.c db.c handler.c hashstr.c \
imm_host.c interp.c mccp.c mssp.c win32srv.c sha256.c

smaug_LDADD = \
libsmaug-act.la libsmaug-player.la libsmaug-mudprog.la \
libsmaug-info.la libsmaug-realm.la

if ENABLE_HOTBOOT
smaug_LDADD += libsmaug-hotboot.la
endif

if IMC
if IMCSMAUG
smaug_LDADD += libsmaug-imc.la
endif
endif

if ENABLE_DNS_RESOLV
smaug_LDADD += libsmaug-dns.la
endif

if HTTPD
# libsmaug-httpd #

libsmaug_httpd_la_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_httpd_la_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
libsmaug_httpd_la_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

libsmaug_httpd_la_SOURCES = mongoose.c

# bin/smaug-httpd #

smaug_httpd_CXXFLAGS = -g -O0 -export-dynamic -Wl,-rpath $(SOLARIS_FLAG) -I../.. -pthread -DMONGOOSE_ENABLE_THREADS -DNS_ENABLE_SSL -lssl
smaug_httpd_CFLAGS = -g -O0 -export-dynamic -Wl,-rpath $(SOLARIS_FLAG) -I../.. -pthread -DMONGOOSE_ENABLE_THREADS -DNS_ENABLE_SSL -lssl
smaug_httpd_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

smaug_httpd_SOURCES = httpd.c

smaug_httpd_LDADD = libsmaug-httpd.la
endif

if ENABLE_DNS_RESOLV
# bin/smaug-resolver #

smaug_resolver_CXXFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
smaug_resolver_CFLAGS = -export-dynamic -Wl,-rpath $(SOLARIS_FLAG)
smaug_resolver_LDFLAGS = -Wl,-rpath $(SOLARIS_LINK) $(LTLIBINTL)

smaug_resolver_SOURCES = resolver.c
endif

# Source Code Headers #

include_HEADERS = \
smaug.h mud.h bet.h calendar.h color.h hint.h \
house.h i18n.h gettext.h liquids.h mapper.h mccp.h mssp.h news.h \
planes.h sha256.h weather.h

if ENABLE_HOTBOOT
include_HEADERS += hotboot.h
endif

if HTTPD
include_HEADERS += mongoose.h
endif

if ENABLE_DNS_RESOLV
include_HEADERS += dns.h
endif

if IMC
if IMCSMAUG
include_HEADERS += imccfg.h imc.h
endif
endif

