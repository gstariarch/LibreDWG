#include "common.c"
#include <dejagnu.h>

void output_process (dwg_object * obj);

void
output_object (dwg_object * obj)
{
  if (!obj)
    {
      printf ("object is NULL\n");
      return;
    }

  if (dwg_get_type (obj) == DWG_TYPE_SHAPE)
    {
      output_process (obj);
    }
}

void
low_level_process (dwg_object * obj)
{
  // casts dwg object to shape entity
  dwg_ent_shape *shape = dwg_object_to_SHAPE (obj);

  // prints thickness of shape
  printf ("Thickness of shape : %f\t\n", shape->thickness);

  // prints extrusion of shape
  printf ("extrusion of shape : x = %f, y = %f, z = %f\t\n",
	  shape->extrusion.x, shape->extrusion.y, shape->extrusion.z);

  // prints ins_pt of shape
  printf ("ins_pt of shape : x = %f,y = %f,z = %f\t\n",
	  shape->ins_pt.x, shape->ins_pt.y, shape->ins_pt.z);
}

void
api_process (dwg_object * obj)
{
  int thickness_error, ins_pt_error, ext_error;
  float thickness;
  dwg_point_3d ins_pt, ext;
  dwg_ent_shape *shape = dwg_object_to_SHAPE (obj);

  // returns thickness
  thickness = dwg_ent_shape_get_thickness (shape, &thickness_error);
  if (thickness_error == 0 && thickness == shape->thickness)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading thickness");
    }

  // returns extrusion
  dwg_ent_shape_get_extrusion (shape, &ext, &ext_error);
  if (ext_error == 0 && shape->extrusion.x == ext.x && shape->extrusion.y == ext.y && shape->extrusion.z == ext.z)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading extrusion");
    }

  // returns insertion point
  dwg_ent_shape_get_ins_pt (shape, &ins_pt, &ins_pt_error);
  if (ins_pt_error == 0 && shape->ins_pt.x == ins_pt.x && shape->ins_pt.y == ins_pt.y && shape->ins_pt.z == ins_pt.z)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading ins_pt");
    }

}
