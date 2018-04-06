$NetBSD: patch-config.h,v 1.1 2013/08/24 08:16:12 ryoon Exp $

--- config.h.orig	2013-02-20 06:30:54.000000000 +0000
+++ config.h
@@ -290,12 +290,6 @@ NAMESPACE_END
 	#define CRYPTOPP_BOOL_AESNI_INTRINSICS_AVAILABLE 0
 #endif
 
-#if CRYPTOPP_BOOL_SSE2_INTRINSICS_AVAILABLE || CRYPTOPP_BOOL_SSE2_ASM_AVAILABLE || defined(CRYPTOPP_X64_MASM_AVAILABLE)
-	#define CRYPTOPP_BOOL_ALIGN16_ENABLED 1
-#else
-	#define CRYPTOPP_BOOL_ALIGN16_ENABLED 0
-#endif
-
 // how to allocate 16-byte aligned memory (for SSE2)
 #if defined(CRYPTOPP_MSVC6PP_OR_LATER)
 	#define CRYPTOPP_MM_MALLOC_AVAILABLE
@@ -307,6 +301,13 @@ NAMESPACE_END
 	#define CRYPTOPP_NO_ALIGNED_ALLOC
 #endif
 
+#if CRYPTOPP_BOOL_SSE2_INTRINSICS_AVAILABLE || CRYPTOPP_BOOL_SSE2_ASM_AVAILABLE || defined(CRYPTOPP_X64_MASM_AVAILABLE) || !defined(CPRYPTO_NO_ALIGNED_ALLOC)
+	#define CRYPTOPP_BOOL_ALIGN16_ENABLED 1
+#else
+	#define CRYPTOPP_BOOL_ALIGN16_ENABLED 0
+#endif
+
+
 // how to disable inlining
 #if defined(_MSC_VER) && _MSC_VER >= 1300
 #	define CRYPTOPP_NOINLINE_DOTDOTDOT
