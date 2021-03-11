cmake_minimum_required(VERSION 3.17)
project(tp_aeds C)

set(CMAKE_C_STANDARD 99)

add_executable(tp_aeds main.c Agenda.h Compromisso.h Agenda.c Compromisso.c ListaCompromissos.c ListaCompromissos.h ListaAgendas.c ListaAgendas.h)