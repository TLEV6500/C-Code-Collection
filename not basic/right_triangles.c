#include <stdio.h>

// Utility objects


// Utility function prototypes that abstract code
// into direct descriptions of the aspects involved in printing a triangle
int get_size(int* rows);
int get_orientation(int* orientation);
int get_choice_if_hollow_or_not(int* is_hollow);
int is_triangle_incomplete(int i, int rows);
int is_row_incomplete(int j, int rows);
int at_hypotenuse(int i, int j, int edge, int orient);
int at_vert_side(int j, int edge, int orient);
int at_hori_size(int i, int edge, int orient);

// Main triangle maker function
void print_right_triangle(int rows, int orientation, int is_hollow);

int main()
{
  int rows, orientation, is_hollow, repeat;

  do
  {
    printf("Make a right triangle!");
    while (if (!get_size(&rows)) return 0, (rows < 0));
    while (get_orientation(&orientation), (orientation < 1 || orientation > 4));
    while (get_choice_if_hollow_or_not(&is_hollow), (is_hollow != 1 || is_hollow != 0));

    print_right_triangle(rows, orientation, is_hollow);
    printf(triangle);
  } while (repeat);

  return 0;
}


// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv--EYES ON THIS FUNCTION FIRST!--vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void print_right_triangle(int rows, int orientation, int is_hollow) {
  const int EDGE = rows - 1;
  const int O = orientation;
  // Construct the triangle
  for (int i = 0; is_triangle_incomplete(i,rows); ++i)
  {
    for (int j = 0; is_row_incomplete(j,rows); ++j)
    {
      if (at_hypotenuse(i, j, EDGE) || at_vert_side(j, EDGE, O) || at_hori_size(i, EDGE, O)) printf("*");
      else printf(" ");
    }
  }
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^--EYES ON THIS FUNCTION FIRST!--^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// Auxiliary functions (submodules) to make the triangle function more abstract and simpler to understand
int is_triangle_incomplete(int i, int rows) {
  return i < rows;
}
int is_row_incomplete(int j, int rows) {
  return j < rows;
}
int at_hypotenuse(int i, int j, int edge, int orient) {
  const int POSITIVELY_SLOPED_HYPOTENUSE = edge - i; // If hypotenuse tilts like a "/"
  const int NEGATIVELY_SLOPED_HYPOTENUSE = i; // If hypotenuse tilts like a "\"
  switch (o) {
    case 1: case 3: // Right Angle is Bottom-Left or Top-Right; They have the same hypotenuse position
      return j == NEGATIVELY_SLOPED_HYPOTENUSE;
    case 2: case 4: // Right Angle is Bottom-Right or Top-Left; They have the same hypotenuse position
      return j == POSITIVELY_SLOPED_HYPOTENUSE;
  }
}
int at_vert_side(int j, int edge, int orient) {
  const int VERTICAL_SIDE_IS_ON_THE_LEFT = 0;
  const int VERTICAL_SIDE_IS_ON_THE_RIGHT = edge;
  switch (orient) {
    case 1: case 4: // Right Angle is Bottom-Left or Top-Left; They have the same vertical side
      return j == VERTICAL_SIDE_IS_ON_THE_LEFT;
    case 2: case 3: // Right Angle is Bottom-Right or Top-Right; They have the same vertical side
      return j == VERTICAL_SIDE_IS_ON_THE_RIGHT;
  }
}
int at_hori_size(int i, int edge, int orient) {
  const int HORIZONTAL_SIDE_IS_FIRST_ROW = i;
  const int HORIZONTAL_SIDE_IS_LAST_ROW = edge;
  switch (orient) {
    case 1: case 2: // Right Angle is Bottom-Left or Bottom-Right; They have the same horizontal side
      return i == HORIZONTAL_SIDE_IS_FIRST_ROW;
    case 3: case 4: // Right Angle is Top-Right or Top-Left; They have the same horizontal side
      return i == HORIZONTAL_SIDE_IS_LAST_ROW;
  }
}


// Utility functions not necessary to understand how to print triangles;
int get_size(int* rows) {
  printf("\nHow many rows? ");
  scanf("%d", rows);
  return rows;
}
int get_orientation(int* orientation) {
  printf("\n[1] Right Angle is Bottom-Left");
  printf("\n[2] Right Angle is Bottom-Right");
  printf("\n[3] Right Angle is Top-Right");
  printf("\n[4] Right Angle is Top-Left");
  printf("\nChoose orientation from above choices: ");
  scanf("%d", orientation);
  return orientation;
}
int get_choice_if_hollow_or_not(int* is_hollow) {
  printf("\nWant a hollow triangle? (0: no, 1: yes) ");
  scanf("%d", &is_hollow);
  return is_hollow;
}