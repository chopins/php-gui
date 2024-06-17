typedef unsigned long gsize;
typedef unsigned int guint;
typedef short gshort;
typedef long glong;
typedef int gint;
typedef gint gboolean;
typedef int GtkWindowType;
typedef gsize GType;
typedef char gchar;
typedef void *gpointer;
typedef unsigned int guint32;
typedef guint32 GQuark;
typedef int GtkOrientation;

typedef struct _GData GData;
typedef struct _GtkWidgetPrivate GtkWidgetPrivate;
typedef struct _GtkContainerPrivate GtkContainerPrivate;
typedef struct _GtkBinPrivate GtkBinPrivate;
typedef struct _GtkWindowPrivate GtkWindowPrivate;
typedef struct _GError GError;
struct _GError
{
    GQuark domain;
    gint code;
    gchar *message;
};

typedef struct _GTypeClass
{
    GType g_type;
} GTypeClass;
typedef struct _GTypeInstance
{
    GTypeClass *g_class;
} GTypeInstance;

typedef struct _GObject
{
    GTypeInstance g_type_instance;
    volatile guint ref_count;
    GData *qdata;
} GObject;

typedef struct _GObject GInitiallyUnowned;

typedef struct _GtkWidget
{
    GInitiallyUnowned parent_instance;
    GtkWidgetPrivate *priv;
} GtkWidget;

typedef struct _GtkContainer
{
    GtkWidget widget;
    GtkContainerPrivate *priv;
} GtkContainer;

typedef struct _GtkBin
{
    GtkContainer container;
    GtkBinPrivate *priv;
} GtkBin;

typedef struct _GtkWindow
{
    GtkBin bin;
    GtkWindowPrivate *priv;
} GtkWindow;

extern GtkWidget *gtk_window_new(GtkWindowType type);
extern void gtk_window_set_title(GtkWindow *window, const gchar *title);
extern const gchar *gtk_window_get_title(GtkWindow *window);
extern void gtk_window_resize(GtkWindow *window, gint width, gint height);
extern void gtk_window_get_size(GtkWindow *window, gint *width, gint *height);
extern void gtk_container_add(GtkContainer *container, GtkWidget *widget);
extern void gtk_widget_show_all(GtkWidget *widget);
extern gpointer g_object_ref(gpointer object);
extern gboolean gtk_widget_get_hexpand(GtkWidget *widget);
extern void gtk_widget_set_hexpand(GtkWidget *widget, gboolean expand);
extern gboolean gtk_widget_get_hexpand_set(GtkWidget *widget);
extern void gtk_widget_set_hexpand_set(GtkWidget *widget, gboolean set);
extern gboolean gtk_widget_get_vexpand(GtkWidget *widget);
extern void gtk_widget_set_vexpand(GtkWidget *widget, gboolean expand);
extern gboolean gtk_widget_get_vexpand_set(GtkWidget *widget);
extern void gtk_widget_set_vexpand_set(GtkWidget *widget, gboolean set);
extern gboolean gtk_window_set_icon_from_file(GtkWindow *window, const gchar *filename, GError **err);
extern gboolean gtk_window_set_default_icon_from_file(const gchar *filename, GError **err);
extern GtkWidget *gtk_box_new(GtkOrientation orientation, gint spacing);