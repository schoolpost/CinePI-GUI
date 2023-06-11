#include "ui/ui.h"
#include <hiredis/hiredis.h>

static int GCD(int a, int b)
{
    int Remainder;

    while( b != 0 )
    {
        Remainder = a % b;
        a = b;
        b = Remainder;
    }

    return a;
}

static void redisSync(redisContext *ctx, redisReply *r){
    r = (redisReply*)redisCommand(ctx, "GET %s", "width");
    if (!r || ctx->err || r->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int width = atoi(r->str);
    freeReplyObject(r);

    r = (redisReply*)redisCommand(ctx, "GET %s", "height");
    if (!r || ctx->err || r->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int height = atoi(r->str);
    freeReplyObject(r);

    // int res_index = 1;
    // if(width == 2028 && height == 1520){
    //     res_index = 2;
    // } else if(width == 2028 && height == 1080){
    //     res_index = 1;
    // } else if(width == 4056 && height == 3040){
    //     res_index = 3;
    // }
    // lv_dropdown_set_selected(ui_dropdownResolution, res_index);

    r = (redisReply*)redisCommand(ctx, "GET %s", "compression");
    if (!r || ctx->err || r->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int compression = atoi(r->str);
    freeReplyObject(r);

    char buffer[32];
    // width/GCD(width,height),height/GCD(width,height)
    sprintf(buffer, "%dx%d     |    12B CDNG:%c\0",width,height,(compression == 7) ? 'L' : 'N');
    lv_label_set_text(ui_formatLabel,(const char *)buffer);
}

static void stateSync(redisContext *ctx, redisReply *r){
    r = (redisReply*)redisCommand(ctx, "GET %s", "width");
    if (!r || ctx->err || r->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int width = atoi(r->str);
    freeReplyObject(r);

    r = (redisReply*)redisCommand(ctx, "GET %s", "height");
    if (!r || ctx->err || r->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int height = atoi(r->str);
    freeReplyObject(r);

    int res_index = 1;
    if(width == 2028 && height == 1520){
        res_index = 2;
    } else if(width == 2028 && height == 1080){
        res_index = 1;
    } else if(width == 4056 && height == 3040){
        res_index = 3;
    }
    lv_dropdown_set_selected(ui_dropdownResolution, res_index);

    int arr_size = 0;

    r = (redisReply*)redisCommand(ctx, "GET %s", "shutter");
    if (!r || ctx->err || r->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int shutter = atoi(r->str);
    freeReplyObject(r);
    arr_size = NELEMS(cpcontrols.shutter);
    for(int i = 0; i < arr_size; i++){
        if(cpcontrols.shutter[i] == shutter){
            lv_roller_set_selected(ui_shutterControl, i, LV_ANIM_ON);
            break;
        }
    }

    r = (redisReply*)redisCommand(ctx, "GET %s", "iso");
    if (!r || ctx->err || r->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int iso = atoi(r->str);
    freeReplyObject(r);
    arr_size = NELEMS(cpcontrols.iso);
    for(int i = 0; i < arr_size; i++){
        if(cpcontrols.iso[i] == iso){
            lv_roller_set_selected(ui_isoControl, i, LV_ANIM_ON);
            break;
        }
    }

    r = (redisReply*)redisCommand(ctx, "GET %s", "fps");
    if (!r || ctx->err || r->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    float fps = atof(r->str);
    freeReplyObject(r);
    arr_size = NELEMS(cpcontrols.fps);
    for(int i = 0; i < arr_size; i++){
        if(cpcontrols.fps[i] == fps){
            lv_roller_set_selected(ui_frameRateControl, i, LV_ANIM_ON);
            break;
        }
    }

    r = (redisReply*)redisCommand(ctx, "GET %s", "wb");
    if (!r || ctx->err || r->type != REDIS_REPLY_STRING) {
        fprintf(stderr, "Error:  Can't send command to Redis\n");
    }
    int wb = atof(r->str);
    freeReplyObject(r);
    arr_size = NELEMS(cpcontrols.wb);
    for(int i = 0; i < arr_size; i++){
        if(cpcontrols.wb[i] == wb){
            lv_roller_set_selected(ui_whiteBalanceControl, i, LV_ANIM_ON);
            break;
        }
    }
}
