#include <pebble.h>

static Window *window;
static Layer *hands_layer, *bg_layer;

static void bg_create_proc(Layer *layer, GContext *ctx) {
    
}

static void hands_update_proc(Layer *layer, GContext *ctx) {
    time_t temp = time(NULL);
    struct tm *t = localtime(&temp);
    GPoint center = GPoint(72, 72);
    
    int32_t minute_angle = TRIG_MAX_ANGLE * t->tm_min / 60;
    int minute_length = 60;
    GPoint minute_point = {
        .x = (int16_t)(sin_lookup(minute_angle) * (int32_t)minute_length / TRIG_MAX_RATIO) + center.x,
        .y = (int16_t)(-cos_lookup(minute_angle) * (int32_t)minute_length / TRIG_MAX_RATIO) + center.y,
    };
    
    
}

static void main_window_load() {
    
}

static void main_window_unload() {
    
}

static void init() {
    window = window_create();
    
    window_set_window_handlers(window, (WindowHandlers) {
        .load = main_window_load,
        .unload = main_window_unload,
    });
    
    window_stack_push(window, true);
}

static void deinit() {
    window_destroy(window);
}

int main(void) {
    init();
    app_event_loop();
    deinit();
    return 0;
}