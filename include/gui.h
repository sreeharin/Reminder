#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *button;
GtkWidget *label0;
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;

void quit(GtkWidget *, gpointer *);
void btn_handler(GtkWidget *, gpointer *);
void break_time(void);
void* display_timer(void *);

#endif