$NetBSD: patch-mozilla_js_src_jit_MIR.cpp,v 1.3 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/js/src/jit/MIR.cpp.orig	2015-09-25 07:35:44.000000000 +0000
+++ mozilla/js/src/jit/MIR.cpp
@@ -72,7 +72,7 @@ MDefinition::PrintOpcodeName(GenericPrin
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        out.printf("%c", tolower(name[i]));
+        out.printf("%c", tolower((unsigned char)name[i]));
 }
 
 const Value&
