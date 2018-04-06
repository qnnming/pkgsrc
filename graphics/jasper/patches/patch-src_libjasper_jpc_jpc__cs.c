$NetBSD: patch-src_libjasper_jpc_jpc__cs.c,v 1.2 2016/05/16 14:03:40 he Exp $

Add fixes for CVE-2011-4516 and CVE-2011-4517.

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jpc/jpc_cs.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_cs.c
@@ -502,7 +502,7 @@ static int jpc_siz_getparms(jpc_ms_t *ms
 	  !siz->tileheight || !siz->numcomps) {
 		return -1;
 	}
-	if (!(siz->comps = jas_malloc(siz->numcomps * sizeof(jpc_sizcomp_t)))) {
+	if (!(siz->comps = jas_alloc2(siz->numcomps, sizeof(jpc_sizcomp_t)))) {
 		return -1;
 	}
 	for (i = 0; i < siz->numcomps; ++i) {
@@ -744,6 +744,10 @@ static int jpc_cox_getcompparms(jpc_ms_t
 		return -1;
 	}
 	compparms->numrlvls = compparms->numdlvls + 1;
+	if (compparms->numrlvls > JPC_MAXRLVLS) {
+		jpc_cox_destroycompparms(compparms);
+		return -1;
+	}
 	if (prtflag) {
 		for (i = 0; i < compparms->numrlvls; ++i) {
 			if (jpc_getuint8(in, &tmp)) {
@@ -982,8 +986,11 @@ static int jpc_qcx_getcompparms(jpc_qcxc
 		compparms->numstepsizes = (len - n) / 2;
 		break;
 	}
-	if (compparms->numstepsizes > 0) {
-		compparms->stepsizes = jas_malloc(compparms->numstepsizes *
+	if (compparms->numstepsizes > 3 * JPC_MAXRLVLS + 1) {
+		jpc_qcx_destroycompparms(compparms);
+                return -1;
+        } else if (compparms->numstepsizes > 0) {
+		compparms->stepsizes = jas_alloc2(compparms->numstepsizes,
 		  sizeof(uint_fast16_t));
 		assert(compparms->stepsizes);
 		for (i = 0; i < compparms->numstepsizes; ++i) {
@@ -1091,7 +1098,7 @@ static int jpc_ppm_getparms(jpc_ms_t *ms
 
 	ppm->len = ms->len - 1;
 	if (ppm->len > 0) {
-		if (!(ppm->data = jas_malloc(ppm->len * sizeof(unsigned char)))) {
+		if (!(ppm->data = jas_malloc(ppm->len))) {
 			goto error;
 		}
 		if (JAS_CAST(uint, jas_stream_read(in, ppm->data, ppm->len)) != ppm->len) {
@@ -1160,7 +1167,7 @@ static int jpc_ppt_getparms(jpc_ms_t *ms
 	}
 	ppt->len = ms->len - 1;
 	if (ppt->len > 0) {
-		if (!(ppt->data = jas_malloc(ppt->len * sizeof(unsigned char)))) {
+		if (!(ppt->data = jas_malloc(ppt->len))) {
 			goto error;
 		}
 		if (jas_stream_read(in, (char *) ppt->data, ppt->len) != JAS_CAST(int, ppt->len)) {
@@ -1223,7 +1230,7 @@ static int jpc_poc_getparms(jpc_ms_t *ms
 	uint_fast8_t tmp;
 	poc->numpchgs = (cstate->numcomps > 256) ? (ms->len / 9) :
 	  (ms->len / 7);
-	if (!(poc->pchgs = jas_malloc(poc->numpchgs * sizeof(jpc_pocpchg_t)))) {
+	if (!(poc->pchgs = jas_alloc2(poc->numpchgs, sizeof(jpc_pocpchg_t)))) {
 		goto error;
 	}
 	for (pchgno = 0, pchg = poc->pchgs; pchgno < poc->numpchgs; ++pchgno,
@@ -1328,7 +1335,7 @@ static int jpc_crg_getparms(jpc_ms_t *ms
 	jpc_crgcomp_t *comp;
 	uint_fast16_t compno;
 	crg->numcomps = cstate->numcomps;
-	if (!(crg->comps = jas_malloc(cstate->numcomps * sizeof(uint_fast16_t)))) {
+	if (!(crg->comps = jas_alloc2(cstate->numcomps, sizeof(jpc_crgcomp_t)))) {
 		return -1;
 	}
 	for (compno = 0, comp = crg->comps; compno < cstate->numcomps;
@@ -1467,7 +1474,7 @@ static int jpc_unk_getparms(jpc_ms_t *ms
 	cstate = 0;
 
 	if (ms->len > 0) {
-		if (!(unk->data = jas_malloc(ms->len * sizeof(unsigned char)))) {
+		if (!(unk->data = jas_malloc(ms->len))) {
 			return -1;
 		}
 		if (jas_stream_read(in, (char *) unk->data, ms->len) != JAS_CAST(int, ms->len)) {
