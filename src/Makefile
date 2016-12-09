#!/usr/bin/make -f

########################################
#
#      Phantasien III v1.9.3alpha
#
#      Basado en SMAUG 1.9 (FUSS)
#
########################################

NOMBRE = phantasienIII
VERSION = 1.9.3alpha
DESCRIPCION = El reino de la dispersion

########################################
# Arquitectura del sistema
########################################

ARCH = `uname -m`

########################################
# Opciones para G++
########################################

CC      = g++
#PROF    = -p

#Descomentar si se obtienen referencias indefinidas para dlsym, dlopen, and dlclose.
#Comentar si se obtienen errores de ldl no encontrado.
NEED_DL = -ldl

#Algunos sistemas necesitan esto para el enlazado dinamico.
EXPORT_SYMBOLS = -export-dynamic

#IMC2 - Comentar para deshabilitar el soporte IMC2 (Mud Network Chat)
IMC = -DIMC

# TODO TODO TODO
# MOB_PROG - Comentar para deshabilitar el soporte de MOB_PROGRAMS
#MOB_PROG = 1

# Descomentar para modo desarrollo/debug  
# Comentar para modo distribucion
# CXX_FLAGS = -Wall -Wshadow -Wformat-security -Wpointer-arith -Wcast-align -Wredundant-decls -Wconversion -Wwrite-strings -Wunused-result

# Descomentar para modo distribucion
# Comentar para modo desarrollo/debug
CXX_FLAGS = -Wno-all -Wno-conversion -fpermissive -Wno-write-strings -Wno-shadow -Wno-format-security -Wno-pointer-arith -Wno-cast-align -Wno-redundant-decls -Wno-unused-result

########################################
# GCC FLAGS Completos
########################################

C_FLAGS = -O -g2 -pipe $(CXX_FLAGS) $(PROF) $(EXPORT_SYMBOLS)
L_FLAGS = $(PROF) -lz $(NEED_DL)

# DNS_FLAGS - Para el proceso resolver_dns, no es neceario enlazar todas las librerias.
DNS_FLAGS = -g2 -O -pipe $(PROF)

########################################
# Ficheros C para compilar
########################################

C_FILES =actualizar.c \
ajedrez.c \
banear.c \
calendario.c \
clanes.c \
clima.c \
color.c \
comentarios.c \
comunicaciones.c \
consejos.c \
constantes.c \
construir.c \
convertir_mapas.c \
crear_objetos.c \
db.c \
deidades.c \
dns.c \
especial.c \
guardar.c \
handler.c \
hashstr.c \
inicio.c \
interprete.c \
jugador.c \
jugador_combate.c \
jugador_comunicaciones.c \
jugador_hechizos.c \
jugador_informacion.c \
jugador_inmortales_seguridad.c \
jugador_magia.c \
jugador_movimiento.c \
jugador_objetos.c \
jugador_polimorfismo.c \
jugador_rastrear.c \
jugador_varios.c \
jugador_wiz.c \
liquidos.c \
mapeador.c \
mccp.c \
mpxset.c \
noticias.c \
phantasienIII.c \
phantasienIII_comunicaciones.c \
planos.c \
renumerar.c \
resetear.c \
sha256.c \
tablas_datos.c \
tableros_de_anuncios.c \
tiendas.c \
variables.c

# Ficheros adicionales para soporte IMC
ifdef IMC
   C_FILES := imc.c $(C_FILES)
   C_FLAGS := $(C_FLAGS) $(IMC) -DIMCSMAUG
endif

# Ficheros adicionales para soporte MOB_PROGRAMS: criaturas||mobprogs
ifdef MOB_PROG
   C_FILES := $(C_FILES) criaturas_programas.c criaturas_comandos.c
   C_FLAGS := $(C_FLAGS) -DDUNNO_STRSTR
endif

# Objetos del compilador se generan en "objetos_compilador"
O_FILES := $(patsubst %.c,objetos_compilador/%.o,$(C_FILES))

H_FILES = $(wildcard *.h) 

########################################
# Construir el codigo
########################################

all:
	@mkdir objetos_compilador
	@echo && echo " [ "$(MAKE)" ] Construccion -> \""$(NOMBRE)" "$(VERSION)" ("$(ARCH)")\"." && echo
	@$(MAKE) -s $(NOMBRE)
	@echo && echo " [ "$(MAKE)" ] Construccion -> \""$(NOMBRE)"\" buscador DNS." && echo
	@$(MAKE) -s resolver_dns
	@echo " [ "$(MAKE)" ] Finalizado! -> \""$(NOMBRE)" "$(VERSION)" ("$(ARCH)")\"." && echo

# Incluir las dependencias para los objetos existentes
-include dependencies.d

$(NOMBRE): $(O_FILES)
	rm -f ../$(NOMBRE)
	$(CC) -export-dynamic -o ../$(NOMBRE) $(O_FILES) $(L_FLAGS)
	@echo && echo " [ "$(MAKE)" ] Generar el fichero de dependencia \"dependencies.d\".";
	@$(CC) -MM $(C_FLAGS) $(C_FILES) > dependencies.d
	@perl -pi -e 's.^([a-z]).o/$$1.g' dependencies.d
	echo " [ "$(MAKE)" ] Finalizada la construccion de: \""$(NOMBRE)"\"."
	chmod g+w ../$(NOMBRE)
	chmod a+x ../$(NOMBRE)
	chmod g+w $(O_FILES)

resolver_dns: objetos_compilador/resolver_dns.o
	rm -f ../resolver_dns
	$(CC) $(DNS_FLAGS) -o ../resolver_dns objetos_compilador/resolver_dns.o
	@echo " [ "$(MAKE)" ] Finalizada la construccion de buscador DNS: \"resolver_dns\"." && echo
	chmod g+w ../resolver_dns
	chmod a+x ../resolver_dns

objetos_compilador/%.o: %.c
	@ echo -n " [ "$(CC)" ] Compilando -> $@ ... "; \
	$(CC) -c $(C_FLAGS) $< -o $@; \
	echo " hecho.";

.c.o: $(NOMBRE).h
	$(CC) -c $(C_FLAGS) $<

clean:
	@rm -rfv objetos_compilador dependencies.d *~ ../*/*~ ../*~

cleanall:
	@rm -rfv ../$(NOMBRE) objetos_compilador dependencies.d ../resolver_dns *~ ../*/*~ ../*~

dist:
	@echo && echo " [ "$(MAKE)" ] Limpiar objetos del codigo y ficheros de log ..." && echo
	@$(MAKE) -s clean && cd .. && touch logs/$(NOMBRE).log && rm -v logs/*
	@echo && echo " [ "$(MAKE)" ] Creando el fichero de distribucion: \"../../"$(NOMBRE)"-"$(VERSION)".tar.bz2\" ..."
	@cd .. && tar cfj ../$(NOMBRE)-$(VERSION).tar.bz2 *
	@echo " [ "$(MAKE)" ] Finalizado." && echo

