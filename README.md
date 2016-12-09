```
/****************************************************************************
 * [S]imulated [M]edieval [A]dventure multi[U]ser [G]ame      |   \\._.//   *
 * -----------------------------------------------------------|   (0...0)   *
 * SMAUG 1.4 (C) 1994, 1995, 1996, 1998  by Derek Snider      |    ).:.(    *
 * -----------------------------------------------------------|    {o o}    *
 * SMAUG code team: Thoric, Altrag, Blodkai, Narn, Haus,      |   / ' ' \   *
 * Scryn, Rennard, Swordbearer, Gorog, Grishnakh, Nivek,      |~'~.VxvxV.~'~*
 * Tricops and Fireblade                                      |             *
 * ------------------------------------------------------------------------ *
 * Merc 2.1 Diku Mud improvments copyright (C) 1992, 1993 by Michael        *
 * Chastain, Michael Quan, and Mitchell Tse.                                *
 * Original Diku Mud copyright (C) 1990, 1991 by Sebastian Hammer,          *
 * Michael Seifert, Hans Henrik St{rfeldt, Tom Madsen, and Katja Nyboe.     *
 * Win32 port by Nick Gammon                                                *
 * ------------------------------------------------------------------------ *
 *                                                                          *
 *                         < Phantasien III >                               *
 *                     "El reino de la desesperacion"                       *
 *                                                                          *
 *                        0ri0n.no-ip.biz:4000                              *
 *                                                                          *
 *                       http://0ri0n.no-ip.biz                             *
 *                                                                          *
 *                      (c) 2014 por BuRZuM-iSHi                            *
 *                                                                          *
 ****************************************************************************/
```

Publicacion inicial basada en el código original de **SMAUGfuss 1.9**.

* Cambios respecto a la antigua version de **Phantasien II** basada en **SMAUG 1.4a**:

	- Mapeados para las zonas
	- Nuevas Zonas
	- Nuevas Clases
	- Soporte para IMC
	- Soporte para MXP
	- Ajedrez

* Nuevas modificaciones realizadas a **SMAUG 1.9fuss** para **Phantasien III**:

	- Estructura: Modificado el nombre de "resolver.c" a "resolver_dns.c"
	- Estructura: Modificado el nombre de los scripts "start" y "qstart" por: "phantasienIII.servidor.completo" y "phantasienIII.servidor.rapido"
	- Estructura: Se añade un fichero de configuracion para el servicio "phantasienIII.servidor.configuracion" que es utilizado por los scripts de inicio.
	- Estructura: Se añade un nuevo script de arranque en modo desarrollo que escribe el log en pantalla llamado "phantasienIII.servidor.desarrollo"
	- Estructura: Se añade $reino/zonas.antiguas (Zonas que deben ser portadas a SMAUGFUSS 1.9)
	- Estructura: Se eliminan ficheros del proyecto de Windows
	- Estructura: Se mueven scripts de desarrollo a "herramientas_desarrollo"
	- Estructura: Revisados los permisos de los ficheros y directorios
	- Estructura: Añadido "editor_zonas_reino": editor de zonas para Windows Area Editor v1.30
	- Estructura: Se modifica "doc" a "Documentacion"
	- Estructura (cambios en ficheros "src"): Se modifica "mud.h" a "phantasienIII.h"
	- Estructura: Se modifica "mud_prog.c" por "phantasienIII.c"
	- Estructura: Se modifica "mud_comm.c" por "phantasienIII_comunicaciones.c"
	- Estructura: Se modifican todos los ficheros para cambiar #include "mud.h" por #include "phantasienIII.h"
	- Estructura: Se añade MOBprograms: "criaturas_programas.c" y "criaturas_comandos.c" (TODO TODO TODO) - EXPERIMENTAL
	- Estructura: Se traduce el nombre de casi todos los ficheros, la intencion es convertirlo a Español.
	- Estructura: Se añade estructura para hermandades (TODO TODO TODO) - EXPERIMENTAL
	- Estructura: Se cambia "area" a nombre del reino de phantasien "reino_de_la_dispersion"
	- Estructura: Cambio de idioma de la estructura del juego
	- Estructura: Se modifican todos los ficheros .gui a .clan
	- Estructura: Se modifican todos los ficheros .dat a .datos
	- Estructura: Se modifican todos los ficheros .lst a .lista
	- Estructura: Se crea el directorio para hermandades
	- Estructura: Se elimina el fichero planes.h se incluye en phantasienIII.h
	- Estructura: Se elimina el fichero services.c (Servicios Win32)
	- Estructura: Se han añadido las antiguas areas de phatasiemII creadas por Yargd.
	- Estructura: Se han renombrado los ficheros .are a .zona
	- Estructura: Se cambia el nombre  de "log" a "logs".
	- Estructura: Se modifican todos los ficheros informativos en .txt que se guardaban en "sistema", ahora se guardan en ../logs/fichero.log
	- Estructura: Se modifican los ficheros .txt de mensajes de tableros de anuncios y noticias ahora son .msg
	- src/Makefile: Modificada la variable "W_FLAGS" para que compile correctamente en Linux, modificar de nuevo para cambiar a modo desarrollo.
	- src/Makefile: Cambiado nombre del ejecutable "smaug" a "phantasienIII"
	- src/Makefile: Cambiado nombre del ejecutable "resolver" a "dnsresolver"
	- src/Makefile: Se añade DESTDIR="../bin" como directorio de instalación y ejecución del servidor
	- src/Makefile: Se elimina la compilación con CygWin y Windows, ahora sólo Linux y BSD
	- src/Makefile: Se añade "cleanall" elimina lo mismo que "clean + ejecutables + logs"
	- src/Makefile: Se añade mob_cmds.c y mob_prog.c a la lista C_FILES
	- src/phantasiemIII.c: Se han traducido las salidas de las cadenas a español.
	- src/db.c: Se han traducido gran parte de las salidas de la base de datos a español.
	- phantasienIII.servidor.completo: Se adapta el fichero de CSH a SH/BASH, se mejora el registro de logs y el formato
	- phantasienIII.servidor.completo: Se modifica el formato para guardar los logs en el directorio logs/.
	- phantasienIII.servidor.completo: Se modifica el nombre de smaug a phantasienIII
	- phantasienIII.servidor.completo: Se cambia "area" a la variable "$reino"
	- phantasienIII.servidor.rapido: No crea un proceso nohup, el servidor no se mantiene en segundo plano, si se cae no se iniciara de nuevo.
	- phantasienIII.servidor.desarrollo: Igual que el anterior pero muestra la salida por pantalla, no guarda logs.
	- phantasienIII.servidor.configuracion: Fichero de configuracion para los scripts de inicio del servidor.


En Proyecto ...
==========

	- Importar las antiguas zonas y enlazarlas con las actuales (reino/zonas.antiguas)
	- (????) Eliminar las zonas de SMAUGFUSS y restaurar las originales del SMAUG de "Realms of despair"
	- Traduccion cadenas de sistema: comandos, liquidos, mezclas, hierbas, ...
	- Traduccion cadenas de zonas y objetos.
	- Traduccion cadenas de clases, razas y clanes. 
	- Traduccion cadenas del tiempo y clima.
	- Traduccion de otras cadenas del juego.
	- Añadir programas Criaturas: MOB_Program
	- Añadir Hermandades: GUILDS

