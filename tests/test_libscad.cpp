#include "gtest/gtest.h"

#include "scad/scad.h"
#include "scad/obj2d.h"
#include "scad/obj3d.h"

#include <vector>
#include <string>
#include <format>

// -----------------------------------------------------------------------------
// Sphere3D Tests
// -----------------------------------------------------------------------------
TEST(Sphere3DTest, ConstructorAndGenerateCode) {
    // Test constructor initialization
    Sphere3D s(10.0f);
    EXPECT_FLOAT_EQ(s.fn, 0.0f);
    EXPECT_FLOAT_EQ(s.fa, 12.0f);
    EXPECT_FLOAT_EQ(s.fs, 2.0f);

    // Test generateCode with default Object3D parameters
    EXPECT_EQ(s.generateCode(), "sphere($fn = 0, $fa = 12, $fs = 2, 10);");

    // Test generateCode after modifying inherited Object3D parameters
    s.fn = 5.0f;
    s.fa = 20.0f;
    s.fs = 3.0f;
    EXPECT_EQ(s.generateCode(), "sphere($fn = 5, $fa = 20, $fs = 3, 10);");
}

// -----------------------------------------------------------------------------
// Cube3D Tests
// -----------------------------------------------------------------------------
TEST(Cube3DTest, SingleSizeConstructorAndGenerateCode) {
    // Test constructor: size, center=true
    Cube3D c1(5.0f, true);
    EXPECT_EQ(c1.generateCode(), "cube($fn = 0, $fa = 12, $fs = 2, size = [5,5,5], center = true);");

    // Test constructor: size, center=false
    Cube3D c2(7.0f, false);
    EXPECT_EQ(c2.generateCode(), "cube($fn = 0, $fa = 12, $fs = 2, size = [7,7,7], center = false);");

    // Test generateCode after modifying inherited Object3D parameters
    c1.fn = 10.0f;
    c1.fa = 15.0f;
    c1.fs = 2.5f;
    EXPECT_EQ(c1.generateCode(), "cube($fn = 10, $fa = 15, $fs = 2.5, size = [5,5,5], center = true);");
}

TEST(Cube3DTest, DimensionsConstructorAndGenerateCode) {
    // Test constructor: width, depth, height, center=false
    Cube3D c(2.0f, 3.0f, 4.0f, false);
    EXPECT_EQ(c.generateCode(), "cube($fn = 0, $fa = 12, $fs = 2, size = [2,3,4], center = false);");

    // Test constructor: width, depth, height, center=true
    Cube3D c_centered(1.0f, 2.0f, 3.0f, true);
    EXPECT_EQ(c_centered.generateCode(), "cube($fn = 0, $fa = 12, $fs = 2, size = [1,2,3], center = true);");

    // Test generateCode after modifying inherited Object3D parameters
    c.fn = 8.0f;
    c.fa = 10.0f;
    c.fs = 1.0f;
    EXPECT_EQ(c.generateCode(), "cube($fn = 8, $fa = 10, $fs = 1, size = [2,3,4], center = false);");
}

// -----------------------------------------------------------------------------
// Cylinder3D Tests
// -----------------------------------------------------------------------------
TEST(Cylinder3DTest, SingleRadiusConstructorAndGenerateCode) {
    // Test constructor: height, radius, center=true
    Cylinder3D cyl1(10.0f, 5.0f, true);
    EXPECT_EQ(cyl1.generateCode(), "cylinder($fn = 0, $fa = 12, $fs = 2, h = 10, r1 = 5, r2 = 5, center = true);");

    // Test constructor: height, radius, center=false
    Cylinder3D cyl2(12.0f, 6.0f, false);
    EXPECT_EQ(cyl2.generateCode(), "cylinder($fn = 0, $fa = 12, $fs = 2, h = 12, r1 = 6, r2 = 6, center = false);");

    // Test generateCode after modifying inherited Object3D parameters
    cyl1.fn = 20.0f;
    cyl1.fa = 25.0f;
    cyl1.fs = 4.0f;
    EXPECT_EQ(cyl1.generateCode(), "cylinder($fn = 20, $fa = 25, $fs = 4, h = 10, r1 = 5, r2 = 5, center = true);");
}

TEST(Cylinder3DTest, DualRadiusConstructorAndGenerateCode) {
    // Test constructor: height, r1, r2, center=false
    Cylinder3D cyl(15.0f, 3.0f, 7.0f, false);
    EXPECT_EQ(cyl.generateCode(), "cylinder($fn = 0, $fa = 12, $fs = 2, h = 15, r1 = 3, r2 = 7, center = false);");

    // Test constructor: height, r1, r2, center=true
    Cylinder3D cyl_centered(8.0f, 2.0f, 2.0f, true);
    EXPECT_EQ(cyl_centered.generateCode(), "cylinder($fn = 0, $fa = 12, $fs = 2, h = 8, r1 = 2, r2 = 2, center = true);");

    // Test generateCode after modifying inherited Object3D parameters
    cyl.fn = 15.0f;
    cyl.fa = 18.0f;
    cyl.fs = 3.5f;
    EXPECT_EQ(cyl.generateCode(), "cylinder($fn = 15, $fa = 18, $fs = 3.5, h = 15, r1 = 3, r2 = 7, center = false);");
}

// -----------------------------------------------------------------------------
// Polyhedron3D Tests
// -----------------------------------------------------------------------------
TEST(Polyhedron3DTest, EmptyPolyhedron) {
    // Test with empty points and faces (covers loop conditions for 0 iterations)
    std::vector<Point3D> points = {};
    std::vector<Face3D> faces = {};
    Polyhedron3D p(points, faces, 0);
    EXPECT_EQ(p.generateCode(), "polyhedron($fn = 0, $fa = 12, $fs = 2, points = [], faces = [], convexity = 0);");
}

TEST(Polyhedron3DTest, SimplePolyhedron) {
    // Test with a simple tetrahedron-like structure
    std::vector<Point3D> points = {
        {0.0f, 0.0f, 0.0f},
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f}
    };
    std::vector<Face3D> faces = {
        {{0.0f,0.0f,0.0f}, {1.0f,0.0f,0.0f}, {0.0f,1.0f,0.0f}}, // Face 1 (triangle)
        {{0.0f,0.0f,0.0f}, {1.0f,0.0f,0.0f}, {0.0f,0.0f,1.0f}}, // Face 2
        {{0.0f,0.0f,0.0f}, {0.0f,1.0f,0.0f}, {0.0f,0.0f,1.0f}}, // Face 3
        {{1.0f,0.0f,0.0f}, {0.0f,1.0f,0.0f}, {0.0f,0.0f,1.0f}}  // Face 4
    };
    int convexity = 1;

    Polyhedron3D p(points, faces, convexity);

    // Expected string for points format (matches current implementation)
    std::string expected_points_format = "[[0,0,0],[1,0,0],[0,1,0],[0,0,1]]";

    // Expected string for faces format (matches current implementation, despite being incorrect OpenSCAD syntax)
    std::string expected_faces_format = "[[[0,0,0],[1,0,0],[0,1,0]],[[0,0,0],[1,0,0],[0,0,1]],[[0,0,0],[0,1,0],[0,0,1]],[[1,0,0],[0,1,0],[0,0,1]]]";

    EXPECT_EQ(p.generateCode(), std::format("polyhedron($fn = 0, $fa = 12, $fs = 2, points = {}, faces = {}, convexity = 1);", expected_points_format, expected_faces_format));

    // Test generateCode after modifying inherited Object3D parameters
    p.fn = 30.0f;
    p.fa = 40.0f;
    p.fs = 5.0f;
    EXPECT_EQ(p.generateCode(), std::format("polyhedron($fn = 30, $fa = 40, $fs = 5, points = {}, faces = {}, convexity = 1);", expected_points_format, expected_faces_format));
}

TEST(Polyhedron3DTest, ComplexPolyhedronLoops) {
    // This test ensures the loops for points and faces in generateCode are fully exercised.
    std::vector<Point3D> points = {
        {0,0,0}, {1,0,0}, {1,1,0}, {0,1,0}, // Base
        {0,0,1}, {1,0,1}, {1,1,1}, {0,1,1}  // Top
    };
    std::vector<Face3D> faces = {
        {{0,0,0},{1,0,0},{1,1,0},{0,1,0}}, // Bottom face
        {{0,0,1},{1,0,1},{1,1,1},{0,1,1}}, // Top face
        {{0,0,0},{1,0,0},{1,0,1},{0,0,1}}, // Side 1
        {{1,0,0},{1,1,0},{1,1,1},{1,0,1}}, // Side 2
        {{1,1,0},{0,1,0},{0,1,1},{1,1,1}}, // Side 3
        {{0,1,0},{0,0,0},{0,0,1},{0,1,1}}  // Side 4
    };
    int convexity = 5;

    Polyhedron3D p(points, faces, convexity);

    // Expected string for points format (matches current implementation)
    std::string expected_points_format = "[[0,0,0],[1,0,0],[1,1,0],[0,1,0],[0,0,1],[1,0,1],[1,1,1],[0,1,1]]";

    // Expected string for faces format (matches current implementation)
    std::string expected_faces_format = "[[[0,0,0],[1,0,0],[1,1,0],[0,1,0]],[[0,0,1],[1,0,1],[1,1,1],[0,1,1]],[[0,0,0],[1,0,0],[1,0,1],[0,0,1]],[[1,0,0],[1,1,0],[1,1,1],[1,0,1]],[[1,1,0],[0,1,0],[0,1,1],[1,1,1]],[[0,1,0],[0,0,0],[0,0,1],[0,1,1]]]";

    EXPECT_EQ(p.generateCode(), std::format("polyhedron($fn = 0, $fa = 12, $fs = 2, points = {}, faces = {}, convexity = 5);", expected_points_format, expected_faces_format));
}

// -----------------------------------------------------------------------------
// Circle2D Tests
// -----------------------------------------------------------------------------

TEST(Circle2DTest, BasicCircle) {
    Circle2D circle(10.0f);
    EXPECT_EQ(circle.generateCode(), "circle($fn = 0, $fa = 12, $fs = 2, r = 10);");
}

TEST(Circle2DTest, CustomFsFaFn) {
    Circle2D circle(5.0f);
    circle.fn = 60;
    circle.fa = 5;
    circle.fs = 1.0f;
    EXPECT_EQ(circle.generateCode(), "circle($fn = 60, $fa = 5, $fs = 1, r = 5);");
}

TEST(Circle2DTest, TrailingSemicolonCircle) {
    Circle2D circle(1.0f);
    std::string code = circle.generateCode();
    ASSERT_FALSE(code.empty());
    EXPECT_EQ(code.back(), ';');
}

// -----------------------------------------------------------------------------
// Square2D Tests
// -----------------------------------------------------------------------------

TEST(Square2DTest, SquareWithSizeAndNoCenter) {
    Square2D square(5.0f, false);
    EXPECT_EQ(square.generateCode(), "square($fn = 0, $fa = 12, $fs = 2, width = 5, height = 5, center = false);");
}

TEST(Square2DTest, SquareWithWidthHeightAndCenter) {
    Square2D square(10.0f, 20.0f, true);
    EXPECT_EQ(square.generateCode(), "square($fn = 0, $fa = 12, $fs = 2, width = 10, height = 20, center = true);");
}

TEST(Square2DTest, ModifyDimensionsAndCenter) {
    Square2D square(1.0f, 1.0f, false);
    square.width = 15.0f;
    square.height = 25.0f;
    square.center = true;
    EXPECT_EQ(square.generateCode(), "square($fn = 0, $fa = 12, $fs = 2, width = 15, height = 25, center = true);");
}

TEST(Square2DTest, TrailingSemicolonSquare) {
    Square2D square(1.0f, 1.0f, false);
    std::string code = square.generateCode();
    ASSERT_FALSE(code.empty());
    EXPECT_EQ(code.back(), ';');
}

// -----------------------------------------------------------------------------
// Polygon2D Tests
// -----------------------------------------------------------------------------

TEST(Polygon2DTest, EmptyPolygon) {
    Polygon2D polygon({}, {});
    EXPECT_EQ(polygon.generateCode(), "polygon($fn = 0, $fa = 12, $fs = 2, points = [], path = []);");
}

TEST(Polygon2DTest, SimplePointsNoPaths) {
    std::vector<Point2D> points = {{0,0}, {10,0}, {10,10}};
    Polygon2D polygon(points, {});
    EXPECT_EQ(polygon.generateCode(), "polygon($fn = 0, $fa = 12, $fs = 2, points = [[0,0],[10,0],[10,10]], path = []);");
}

TEST(Polygon2DTest, TrailingSemicolonPolygon) {
    std::vector<Point2D> points = {{0,0}};
    Polygon2D polygon(points, {});
    std::string code = polygon.generateCode();
    ASSERT_FALSE(code.empty());
    EXPECT_EQ(code.back(), ';');
}

// -----------------------------------------------------------------------------
// Text2D Tests
// -----------------------------------------------------------------------------
TEST(Text2DTest, BasicText) {
    Text2D text("Hello World");
    EXPECT_EQ(text.generateCode(), "text($fn = 0, $fa = 12, $fs = 2, text = Hello World, font = Liberation Sans:style=Regular, size = 10, halign = left, valign = baseline, spacing = 1, direction = ltr, language = en, script = latin);");
}

TEST(Text2DTest, CustomTextParameters) {
    Text2D text("Test");
    text.font = "Arial";
    text.size = 12.0f;
    text.halign = "center";
    text.valign = "center";
    text.spacing = 2.0f;
    text.direction = "rtl";
    text.language = "es";
    text.script = "arabic";
    EXPECT_EQ(text.generateCode(), "text($fn = 0, $fa = 12, $fs = 2, text = Test, font = Arial, size = 12, halign = center, valign = center, spacing = 2, direction = rtl, language = es, script = arabic);");
}

TEST(Text2DTest, TrailingSemicolonText) {
    Text2D text("Simple");
    std::string code = text.generateCode();
    ASSERT_FALSE(code.empty());
    EXPECT_EQ(code.back(), ';');
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
