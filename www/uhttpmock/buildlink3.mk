# $NetBSD: buildlink3.mk,v 1.3 2016/05/03 11:40:10 prlw1 Exp $

BUILDLINK_TREE+=	uhttpmock

.if !defined(UHTTPMOCK_BUILDLINK3_MK)
UHTTPMOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhttpmock+=	uhttpmock>=0.4.0
BUILDLINK_ABI_DEPENDS.uhttpmock?=	uhttpmock>=0.4.0nb5
BUILDLINK_PKGSRCDIR.uhttpmock?=	../../www/uhttpmock

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.endif	# UHTTPMOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhttpmock