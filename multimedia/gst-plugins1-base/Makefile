# $NetBSD: Makefile,v 1.13 2016/09/12 09:00:10 wiz Exp $

.include "Makefile.common"

#CONFIGURE_ARGS+= --disable-silent-rules

COMMENT+=	Base plugins

USE_TOOLS+=	perl:run
MAKE_JOBS_SAFE=		no
PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../mk/bsd.prefs.mk"

# This define is checked but never set, enable it on Solaris.
CFLAGS.SunOS+=		-DHAVE_FIONREAD_IN_SYS_FILIO=1

# soft dependency only, .pc file not needed
#.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
