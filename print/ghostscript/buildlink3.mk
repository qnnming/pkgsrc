# $NetBSD: buildlink3.mk,v 1.19 2016/03/05 11:27:53 jperkin Exp $

BUILDLINK_TREE+=	ghostscript

.if !defined(GHOSTSCRIPT_BUILDLINK3_MK)
GHOSTSCRIPT_BUILDLINK3_MK:=	1

BUILDLINK_API_DEPENDS.ghostscript+=	ghostscript>=8.63nb1
BUILDLINK_ABI_DEPENDS.ghostscript+= 	ghostscript>=9.05nb8
BUILDLINK_PKGSRCDIR.ghostscript=	../../print/ghostscript

pkgbase := ghostscript
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.ghostscript:Mghostscript-agpl)
.include "../../print/ghostscript-agpl/buildlink3.mk"
.elif !empty(PKG_BUILD_OPTIONS.ghostscript:Mghostscript-gpl)
.include "../../print/ghostscript-gpl/buildlink3.mk"
.endif

.endif # GHOSTSCRIPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghostscript
