#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Structure to hold calculator state
typedef struct {
    GtkWidget *display;
    double first_num;
    char operator;
    gboolean clear_next;
} CalcData;

// Handle number button clicks (0-9) and decimal point (.)
static void on_number_clicked(GtkWidget *widget, gpointer user_data) {
    CalcData *data = (CalcData *)user_data;
    const char *label = gtk_button_get_label(GTK_BUTTON(widget));
    const char *current = gtk_editable_get_text(GTK_EDITABLE(data->display));

    if (data->clear_next || strcmp(current, "0") == 0 || strcmp(current, "Error") == 0) {
        if (strcmp(label, ".") == 0) {
            gtk_editable_set_text(GTK_EDITABLE(data->display), "0.");
        } else {
            gtk_editable_set_text(GTK_EDITABLE(data->display), label);
        }
        data->clear_next = FALSE;
    } else {
        // Prevent multiple decimal points in one number
        if (strcmp(label, ".") == 0 && strchr(current, '.') != NULL) {
            return;
        }
        char buffer[128];
        snprintf(buffer, sizeof(buffer), "%s%s", current, label);
        gtk_editable_set_text(GTK_EDITABLE(data->display), buffer);
    }
}

// Handle operator button clicks (+, -, *, /)
static void on_operator_clicked(GtkWidget *widget, gpointer user_data) {
    CalcData *data = (CalcData *)user_data;
    const char *label = gtk_button_get_label(GTK_BUTTON(widget));
    const char *current = gtk_editable_get_text(GTK_EDITABLE(data->display));

    data->first_num = atof(current);
    data->operator = label[0];
    data->clear_next = TRUE;
}

// Handle equals button (=)
static void on_equals_clicked(GtkWidget *widget, gpointer user_data) {
    CalcData *data = (CalcData *)user_data;
    const char *current = gtk_editable_get_text(GTK_EDITABLE(data->display));
    double second_num = atof(current);
    double result = 0.0;

    if (data->operator == 0) return;

    if (data->operator == '/' && second_num == 0) {
        gtk_editable_set_text(GTK_EDITABLE(data->display), "Error");
        data->operator = 0;
        data->clear_next = TRUE;
        return;
    }

    switch (data->operator) {
        case '+': result = data->first_num + second_num; break;
        case '-': result = data->first_num - second_num; break;
        case '*': result = data->first_num * second_num; break;
        case '/': result = data->first_num / second_num; break;
    }

    char buffer[128];
    // %g automatically strips unnecessary trailing zeros
    snprintf(buffer, sizeof(buffer), "%g", result);
    gtk_editable_set_text(GTK_EDITABLE(data->display), buffer);

    data->operator = 0;
    data->clear_next = TRUE;
}

// Handle Clear button (C)
static void on_clear_clicked(GtkWidget *widget, gpointer user_data) {
    CalcData *data = (CalcData *)user_data;
    gtk_editable_set_text(GTK_EDITABLE(data->display), "0");
    data->first_num = 0;
    data->operator = 0;
    data->clear_next = FALSE;
}

// Build the GUI layout
static void activate(GtkApplication *app, gpointer user_data) {
    CalcData *data = g_new0(CalcData, 1);

    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 260, 320);

    // Create a grid container with 5px spacing
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    // Create the read-only display screen
    data->display = gtk_entry_new();
    gtk_editable_set_text(GTK_EDITABLE(data->display), "0");
    gtk_editable_set_editable(GTK_EDITABLE(data->display), FALSE);
    gtk_entry_set_alignment(GTK_ENTRY(data->display), 1.0); // Right-align text
    gtk_widget_set_hexpand(data->display, TRUE);
    // Attach display at col 0, row 0, spanning 4 columns wide and 1 row tall
    gtk_grid_attach(GTK_GRID(grid), data->display, 0, 0, 4, 1);

    // Define the 4x4 button layout
    const char *buttons[4][4] = {
        {"7", "8", "9", "/"},
        {"4", "5", "6", "*"},
        {"1", "2", "3", "-"},
        {"C", "0", "=", "+"}
    };

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            const char *label = buttons[row][col];
            GtkWidget *btn = gtk_button_new_with_label(label);
            gtk_widget_set_hexpand(btn, TRUE);
            gtk_widget_set_vexpand(btn, TRUE);

            // Connect the right callback for each button type
            if (strcmp(label, "C") == 0) {
                g_signal_connect(btn, "clicked", G_CALLBACK(on_clear_clicked), data);
            } else if (strcmp(label, "=") == 0) {
                g_signal_connect(btn, "clicked", G_CALLBACK(on_equals_clicked), data);
            } else if (strchr("+-*/", label[0]) != NULL) {
                g_signal_connect(btn, "clicked", G_CALLBACK(on_operator_clicked), data);
            } else {
                g_signal_connect(btn, "clicked", G_CALLBACK(on_number_clicked), data);
            }

            // Attach button to grid (row + 1 because row 0 is the display)
            gtk_grid_attach(GTK_GRID(grid), btn, col, row + 1, 1, 1);
        }
    }

    // Add a decimal point button spanning the bottom row
    GtkWidget *dot_btn = gtk_button_new_with_label(".");
    gtk_widget_set_hexpand(dot_btn, TRUE);
    gtk_widget_set_vexpand(dot_btn, TRUE);
    g_signal_connect(dot_btn, "clicked", G_CALLBACK(on_number_clicked), data);
    gtk_grid_attach(GTK_GRID(grid), dot_btn, 0, 5, 4, 1);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("org.example.calculator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

