# $NetBSD: Makefile,v 1.7 2016/08/17 00:06:41 ryoon Exp $

DISTNAME=	spek-0.8.2
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	https://spek.googlecode.com/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://spek.cc/
COMMENT=	Acoustic Spectrum Analyzer
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake intltool xgettext msgmerge msgfmt pkg-config
MAKE_FLAGS+=	DATADIRNAME=${PKGLOCALEDIR}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
