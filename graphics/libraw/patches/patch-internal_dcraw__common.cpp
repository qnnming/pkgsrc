$NetBSD: patch-internal_dcraw__common.cpp,v 1.1 2016/06/19 05:04:57 markd Exp $

gcc6 fix

--- internal/dcraw_common.cpp.orig	2016-05-14 06:55:03.000000000 +0000
+++ internal/dcraw_common.cpp
@@ -4513,30 +4513,37 @@ void CLASS lin_interpolate()
  */
 void CLASS vng_interpolate()
 {
-  static const signed char *cp, terms[] = {
-    -2,-2,+0,-1,0,0x01, -2,-2,+0,+0,1,0x01, -2,-1,-1,+0,0,0x01,
-    -2,-1,+0,-1,0,0x02, -2,-1,+0,+0,0,0x03, -2,-1,+0,+1,1,0x01,
-    -2,+0,+0,-1,0,0x06, -2,+0,+0,+0,1,0x02, -2,+0,+0,+1,0,0x03,
-    -2,+1,-1,+0,0,0x04, -2,+1,+0,-1,1,0x04, -2,+1,+0,+0,0,0x06,
-    -2,+1,+0,+1,0,0x02, -2,+2,+0,+0,1,0x04, -2,+2,+0,+1,0,0x04,
-    -1,-2,-1,+0,0,0x80, -1,-2,+0,-1,0,0x01, -1,-2,+1,-1,0,0x01,
-    -1,-2,+1,+0,1,0x01, -1,-1,-1,+1,0,0x88, -1,-1,+1,-2,0,0x40,
-    -1,-1,+1,-1,0,0x22, -1,-1,+1,+0,0,0x33, -1,-1,+1,+1,1,0x11,
-    -1,+0,-1,+2,0,0x08, -1,+0,+0,-1,0,0x44, -1,+0,+0,+1,0,0x11,
-    -1,+0,+1,-2,1,0x40, -1,+0,+1,-1,0,0x66, -1,+0,+1,+0,1,0x22,
-    -1,+0,+1,+1,0,0x33, -1,+0,+1,+2,1,0x10, -1,+1,+1,-1,1,0x44,
-    -1,+1,+1,+0,0,0x66, -1,+1,+1,+1,0,0x22, -1,+1,+1,+2,0,0x10,
-    -1,+2,+0,+1,0,0x04, -1,+2,+1,+0,1,0x04, -1,+2,+1,+1,0,0x04,
-    +0,-2,+0,+0,1,0x80, +0,-1,+0,+1,1,0x88, +0,-1,+1,-2,0,0x40,
-    +0,-1,+1,+0,0,0x11, +0,-1,+2,-2,0,0x40, +0,-1,+2,-1,0,0x20,
-    +0,-1,+2,+0,0,0x30, +0,-1,+2,+1,1,0x10, +0,+0,+0,+2,1,0x08,
-    +0,+0,+2,-2,1,0x40, +0,+0,+2,-1,0,0x60, +0,+0,+2,+0,1,0x20,
-    +0,+0,+2,+1,0,0x30, +0,+0,+2,+2,1,0x10, +0,+1,+1,+0,0,0x44,
-    +0,+1,+1,+2,0,0x10, +0,+1,+2,-1,1,0x40, +0,+1,+2,+0,0,0x60,
-    +0,+1,+2,+1,0,0x20, +0,+1,+2,+2,0,0x10, +1,-2,+1,+0,0,0x80,
-    +1,-1,+1,+1,0,0x88, +1,+0,+1,+2,0,0x08, +1,+0,+2,-1,0,0x40,
-    +1,+0,+2,+1,0,0x10
-  }, chood[] = { -1,-1, -1,0, -1,+1, 0,+1, +1,+1, +1,0, +1,-1, 0,-1 };
+  struct interpolate_terms {
+    signed char y1, x1, y2, x2, weight;
+    unsigned char grads;
+  };
+  static const interpolate_terms terms[] = {
+    {-2,-2,+0,-1,0,0x01}, {-2,-2,+0,+0,1,0x01}, {-2,-1,-1,+0,0,0x01},
+    {-2,-1,+0,-1,0,0x02}, {-2,-1,+0,+0,0,0x03}, {-2,-1,+0,+1,1,0x01},
+    {-2,+0,+0,-1,0,0x06}, {-2,+0,+0,+0,1,0x02}, {-2,+0,+0,+1,0,0x03},
+    {-2,+1,-1,+0,0,0x04}, {-2,+1,+0,-1,1,0x04}, {-2,+1,+0,+0,0,0x06},
+    {-2,+1,+0,+1,0,0x02}, {-2,+2,+0,+0,1,0x04}, {-2,+2,+0,+1,0,0x04},
+    {-1,-2,-1,+0,0,0x80}, {-1,-2,+0,-1,0,0x01}, {-1,-2,+1,-1,0,0x01},
+    {-1,-2,+1,+0,1,0x01}, {-1,-1,-1,+1,0,0x88}, {-1,-1,+1,-2,0,0x40},
+    {-1,-1,+1,-1,0,0x22}, {-1,-1,+1,+0,0,0x33}, {-1,-1,+1,+1,1,0x11},
+    {-1,+0,-1,+2,0,0x08}, {-1,+0,+0,-1,0,0x44}, {-1,+0,+0,+1,0,0x11},
+    {-1,+0,+1,-2,1,0x40}, {-1,+0,+1,-1,0,0x66}, {-1,+0,+1,+0,1,0x22},
+    {-1,+0,+1,+1,0,0x33}, {-1,+0,+1,+2,1,0x10}, {-1,+1,+1,-1,1,0x44},
+    {-1,+1,+1,+0,0,0x66}, {-1,+1,+1,+1,0,0x22}, {-1,+1,+1,+2,0,0x10},
+    {-1,+2,+0,+1,0,0x04}, {-1,+2,+1,+0,1,0x04}, {-1,+2,+1,+1,0,0x04},
+    {+0,-2,+0,+0,1,0x80}, {+0,-1,+0,+1,1,0x88}, {+0,-1,+1,-2,0,0x40},
+    {+0,-1,+1,+0,0,0x11}, {+0,-1,+2,-2,0,0x40}, {+0,-1,+2,-1,0,0x20},
+    {+0,-1,+2,+0,0,0x30}, {+0,-1,+2,+1,1,0x10}, {+0,+0,+0,+2,1,0x08},
+    {+0,+0,+2,-2,1,0x40}, {+0,+0,+2,-1,0,0x60}, {+0,+0,+2,+0,1,0x20},
+    {+0,+0,+2,+1,0,0x30}, {+0,+0,+2,+2,1,0x10}, {+0,+1,+1,+0,0,0x44},
+    {+0,+1,+1,+2,0,0x10}, {+0,+1,+2,-1,1,0x40}, {+0,+1,+2,+0,0,0x60},
+    {+0,+1,+2,+1,0,0x20}, {+0,+1,+2,+2,0,0x10}, {+1,-2,+1,+0,0,0x80},
+    {+1,-1,+1,+1,0,0x88}, {+1,+0,+1,+2,0,0x08}, {+1,+0,+2,-1,0,0x40},
+    {+1,+0,+2,+1,0,0x10}
+  };
+  const interpolate_terms *cpt;
+  signed char *cp;
+  signed char chood[] = { -1,-1, -1,0, -1,+1, 0,+1, +1,+1, +1,0, +1,-1, 0,-1 };
   ushort (*brow[5])[4], *pix;
   int prow=8, pcol=2, *ip, *code[16][16], gval[8], gmin, gmax, sum[4];
   int row, col, x, y, x1, x2, y1, y2, t, weight, grads, color, diag;
@@ -4554,11 +4561,11 @@ void CLASS vng_interpolate()
   for (row=0; row < prow; row++)		/* Precalculate for VNG */
     for (col=0; col < pcol; col++) {
       code[row][col] = ip;
-      for (cp=terms, t=0; t < 64; t++) {
-	y1 = *cp++;  x1 = *cp++;
-	y2 = *cp++;  x2 = *cp++;
-	weight = *cp++;
-	grads = *cp++;
+      for (cpt=&terms[0], t=0; t < 64, cpt = &terms[t]; t++) {
+	y1 = cpt->y1;  x1 = cpt->x1;
+	y2 = cpt->y2;  x2 = cpt->x2;
+	weight = cpt->weight;
+	grads = cpt->grads;
 	color = fcol(row+y1,col+x1);
 	if (fcol(row+y2,col+x2) != color) continue;
 	diag = (fcol(row,col+1) == color && fcol(row+1,col) == color) ? 2:1;
