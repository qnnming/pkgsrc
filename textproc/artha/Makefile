# $NetBSD: Makefile,v 1.2 2016/08/03 10:23:27 adam Exp $

DISTNAME=       artha-1.0.3
PKGREVISION=     1
CATEGORIES=     textproc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=artha/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       http://artha.sourceforge.net/
COMMENT=        Open Source WordNet-based thesaurus
LICENSE=        gnu-gpl-v2

GNU_CONFIGURE=  yes
USE_LIBTOOL=    yes
USE_TOOLS+=     autoconf automake gmake pkg-config
USE_LANGUAGES=  c

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/WordNet/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
