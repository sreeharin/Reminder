#include <pthread.h>
#include "gui.h"
#include "tools.h"

void
quit(GtkWidget *widget, gpointer *data)
{
    gtk_main_quit();
}

void
btn_handler(GtkWidget *widget, gpointer *data)
{
    gtk_window_iconify(GTK_WINDOW(window));

	gtk_label_set_text((GtkLabel *)label0, NULL);
	gtk_label_set_text((GtkLabel *)label1, NULL);
	gtk_label_set_text((GtkLabel *)label2, "Count down until next break");
	pthread_t t1;
	pthread_create(&t1, NULL, display_timer, (void *)label3);

	gtk_button_set_label(GTK_BUTTON(button), "I\'m back");
    gtk_widget_set_sensitive(button, FALSE); 
}

void 
break_time(void)
{
    gtk_window_present(GTK_WINDOW(window));
	gtk_label_set_text((GtkLabel *)label1, "Time for break!");
    gtk_label_set_text((GtkLabel *)label0, NULL);
	gtk_label_set_text((GtkLabel *)label2, NULL);
	gtk_label_set_text((GtkLabel *)label3, NULL);
    gtk_widget_set_sensitive(button, TRUE); 

}

void *
display_timer(void * label)
{
    GtkLabel *tmp_label = (GtkLabel *)label;

    int min=0;
    readData(&min);
	
    int seconds = min * 60;

	for(int i = seconds; i >= 0; i--)
	{
		char data[10];
		int hr = i/(60*60);
        int min = (i%(60*60))/60;
        int sec = i%60;
		sprintf(data, "%02d:%02d:%02d", hr, min, sec);
		gtk_label_set_text(tmp_label, data);
		sleep(1);
	}
	break_time();
}
