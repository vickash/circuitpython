#include "shared-bindings/vectorio/__init__.h"
#include "shared-bindings/vectorio/Rectangle.h"
#include "shared-module/vectorio/VectorShape.h"
#include "shared-bindings/vectorio/VectorShape.h"

#include <stdint.h>

#include "py/objtype.h"
#include "py/runtime.h"
#include "supervisor/shared/translate.h"

//| class Rectangle:
//|     def __init__(self, pixel_shader: Union[displayio.ColorConverter, displayio.Palette], width: int, height: int, x: int, y: int) -> None:
//|         """Represents a rectangle by defining its bounds
//|
//|            :param Union[~displayio.ColorConverter,~displayio.Palette] pixel_shader: The pixel shader that produces colors from values
//|            :param int width: The number of pixels wide
//|            :param int height: The number of pixels high
//|            :param int x: Initial x position of the top left corner.
//|            :param int y: Initial y position of the top left corner."""
//|
static mp_obj_t vectorio_rectangle_make_new(const mp_obj_type_t *type, size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_pixel_shader, ARG_width, ARG_height, ARG_x, ARG_y };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_pixel_shader, MP_ARG_OBJ | MP_ARG_KW_ONLY | MP_ARG_REQUIRED },
        { MP_QSTR_width, MP_ARG_REQUIRED | MP_ARG_INT },
        { MP_QSTR_height, MP_ARG_REQUIRED | MP_ARG_INT },
        { MP_QSTR_x, MP_ARG_INT | MP_ARG_KW_ONLY, {.u_int = 0} },
        { MP_QSTR_y, MP_ARG_INT | MP_ARG_KW_ONLY, {.u_int = 0} },
    };
    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    mp_int_t width = args[ARG_width].u_int;
    if (width < 1) {
        mp_raise_ValueError_varg(translate("%q must be >= 1"), MP_QSTR_width);
    }
    mp_int_t height = args[ARG_height].u_int;
    if (height < 1) {
        mp_raise_ValueError_varg(translate("%q must be >= 1"), MP_QSTR_height);
    }

    vectorio_rectangle_t *self = m_new_obj(vectorio_rectangle_t);
    self->base.type = &vectorio_rectangle_type;
    common_hal_vectorio_rectangle_construct(self, width, height);

    // VectorShape parts
    mp_obj_t pixel_shader = args[ARG_pixel_shader].u_obj;
    int32_t x = args[ARG_x].u_int;
    int32_t y = args[ARG_y].u_int;
    mp_obj_t vector_shape = vectorio_vector_shape_make_new(self, pixel_shader, x, y);
    self->draw_protocol_instance = vector_shape;

    return MP_OBJ_FROM_PTR(self);
}

STATIC const vectorio_draw_protocol_t rectangle_draw_protocol = {
    MP_PROTO_IMPLEMENT(MP_QSTR_protocol_draw)
    .draw_get_protocol_self = (draw_get_protocol_self_fun)common_hal_vectorio_rectangle_get_draw_protocol,
    .draw_protocol_impl = &vectorio_vector_shape_draw_protocol_impl
};


// Documentation for properties inherited from VectorShape.

//|     x : int
//|     """X position of the top left corner of the rectangle in the parent."""
//|
//|     y : int
//|     """Y position of the top left corner of the rectangle in the parent."""
//|
//|     location : Tuple[int,int]
//|     """(X,Y) position of the top left corner of the rectangle in the parent."""
//|
//|     pixel_shader : Union[displayio.ColorConverter,displayio.Palette]
//|     """The pixel shader of the rectangle."""
//|

STATIC const mp_rom_map_elem_t vectorio_rectangle_locals_dict_table[] = {
    // Properties
    { MP_ROM_QSTR(MP_QSTR_x), MP_ROM_PTR(&vectorio_vector_shape_x_obj) },
    { MP_ROM_QSTR(MP_QSTR_y), MP_ROM_PTR(&vectorio_vector_shape_y_obj) },
    { MP_ROM_QSTR(MP_QSTR_location), MP_ROM_PTR(&vectorio_vector_shape_location_obj) },
    { MP_ROM_QSTR(MP_QSTR_pixel_shader), MP_ROM_PTR(&vectorio_vector_shape_pixel_shader_obj) },
};
STATIC MP_DEFINE_CONST_DICT(vectorio_rectangle_locals_dict, vectorio_rectangle_locals_dict_table);

const mp_obj_type_t vectorio_rectangle_type = {
    { &mp_type_type },
    .name = MP_QSTR_Rectangle,
    .flags = MP_TYPE_FLAG_EXTENDED,
    .make_new = vectorio_rectangle_make_new,
    .locals_dict = (mp_obj_dict_t *)&vectorio_rectangle_locals_dict,
    MP_TYPE_EXTENDED_FIELDS(
        .protocol = &rectangle_draw_protocol,
        ),
};
