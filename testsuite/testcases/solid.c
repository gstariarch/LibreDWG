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

  if (dwg_get_type (obj) == DWG_TYPE_SOLID)
    {
      output_process (obj);
    }
}

void
low_level_process (dwg_object * obj)
{
  // casts object to solid entity
  dwg_ent_solid *solid = dwg_object_to_SOLID (obj);

  // prints elevation
  printf ("elevation of solid : %f\t\n", solid->elevation);

  // prints thickness
  printf ("thickness of solid : %f\t\n", solid->thickness);

  // prints extrusion
  printf ("extrusion of solid : x = %f, y = %f, z = %f\t\n",
	  solid->extrusion.x, solid->extrusion.y, solid->extrusion.z);

  // prints corner 1
  printf ("corner1 of solid : x = %f, y = %f\t\n", solid->corner1.x,
	  solid->corner1.y);

  // prints corner 2
  printf ("corner2 of solid : x = %f, y = %f\t\n", solid->corner2.x,
	  solid->corner2.y);

  // prints corner 3
  printf ("corner3 of solid : x = %f, y = %f\t\n", solid->corner3.x,
	  solid->corner3.y);

  // prints corner 4
  printf ("corner4 of solid : x = %f, y = %f\t\n", solid->corner4.x,
	  solid->corner4.y);

}

void
api_process (dwg_object * obj)
{
  int elevation_error, ext_error, thickness_error, c1_error, c2_error,
    c3_error, c4_error;
  float thickness, elevation;
  dwg_point_3d ext;
  dwg_point_2d c1, c2, c3, c4;
  dwg_ent_solid *solid = dwg_object_to_SOLID (obj);

  // prints elevation
  elevation = dwg_ent_solid_get_elevation (solid, &elevation_error);
  if (elevation_error == 0 && solid->elevation == elevation)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading elevation");
    }

  // returns thickness
  thickness = dwg_ent_solid_get_thickness (solid, &thickness_error);
  if (thickness_error == 0 && thickness == solid->thickness)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading thickness");
    }

  // returns extrusion
  dwg_ent_solid_get_extrusion (solid, &ext, &ext_error);
  if (ext_error == 0 && ext.x == solid->extrusion.x && ext.y == solid->extrusion.y && ext.z == solid->extrusion.z)	// error checks
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading extrusion");
    }

  // returns corner 1
  dwg_ent_solid_get_corner1 (solid, &c1, &c1_error);
  if (c1_error == 0 && solid->corner1.x == c1.x && solid->corner1.y == c1.y)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading corner 1");
    }

  // returns corner 2
  dwg_ent_solid_get_corner2 (solid, &c2, &c2_error);
  if (c2_error == 0 && solid->corner2.x == c2.x && solid->corner2.y == c2.y)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading corner 2");
    }

  // returns corner 3
  dwg_ent_solid_get_corner3 (solid, &c3, &c3_error);
  if (c3_error == 0 && solid->corner3.x == c3.x && solid->corner3.y == c3.y)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading corner 3");
    }

  // returns corner 4
  dwg_ent_solid_get_corner4 (solid, &c4, &c4_error);
  if (c4_error == 0 && solid->corner4.x == c4.x && solid->corner4.y == c4.y)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading corner 4 \n");
    }

}
