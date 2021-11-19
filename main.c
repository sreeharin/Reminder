#include <gtk/gtk.h>

#include "gui.h"

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Break reminder");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    g_signal_connect(window, "destroy", G_CALLBACK(quit), NULL);

    GtkWidget *layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), layout);

    label0 = gtk_label_new("Start timer by pressing the button");
    label1 = gtk_label_new(NULL);
    label2 = gtk_label_new(NULL);
    label3 = gtk_label_new(NULL);

    button = gtk_button_new_with_label("Start");
    g_signal_connect(GTK_BUTTON(button), "clicked", G_CALLBACK(btn_handler), NULL);

    gtk_layout_put(GTK_LAYOUT(layout), label0, 50, 60);
    gtk_layout_put(GTK_LAYOUT(layout), label1, 95, 60);
    gtk_layout_put(GTK_LAYOUT(layout), label2, 65, 30);
    gtk_layout_put(GTK_LAYOUT(layout), label3, 125, 60);
    gtk_layout_put(GTK_LAYOUT(layout), button, 200, 160);

    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
