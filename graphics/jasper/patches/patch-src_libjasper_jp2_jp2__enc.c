$NetBSD: patch-src_libjasper_jp2_jp2__enc.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jp2/jp2_enc.c.orig	2007-01-19 21:43:05.000000000 +0000
+++ src/libjasper/jp2/jp2_enc.c
@@ -191,7 +191,7 @@ int sgnd;
 		}
 		bpcc = &box->data.bpcc;
 		bpcc->numcmpts = jas_image_numcmpts(image);
-		if (!(bpcc->bpcs = jas_malloc(bpcc->numcmpts *
+		if (!(bpcc->bpcs = jas_alloc2(bpcc->numcmpts,
 		  sizeof(uint_fast8_t)))) {
 			goto error;
 		}
@@ -285,7 +285,7 @@ int sgnd;
 		}
 		cdef = &box->data.cdef;
 		cdef->numchans = jas_image_numcmpts(image);
-		cdef->ents = jas_malloc(cdef->numchans * sizeof(jp2_cdefchan_t));
+		cdef->ents = jas_alloc2(cdef->numchans, sizeof(jp2_cdefchan_t));
 		for (i = 0; i < jas_image_numcmpts(image); ++i) {
 			cdefchanent = &cdef->ents[i];
 			cdefchanent->channo = i;
@@ -343,7 +343,8 @@ int sgnd;
 	/* Output the JPEG-2000 code stream. */
 
 	overhead = jas_stream_getrwcount(out);
-	sprintf(buf, "%s\n_jp2overhead=%lu\n", (optstr ? optstr : ""),
+	snprintf(buf, sizeof buf, "%s\n_jp2overhead=%lu\n", 
+	  (optstr ? optstr : ""),
 	  (unsigned long) overhead);
 
 	if (jpc_encode(image, out, buf)) {
