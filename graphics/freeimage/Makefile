# $NetBSD: Makefile,v 1.2 2015/05/27 21:59:26 markd Exp $

DISTNAME=	FreeImage3170
PKGNAME=	freeimage-3.17.0
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeimage/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeimage.sf.net/
COMMENT=	Library for supporting PNG, BMP, JPEG, and TIFF

USE_LANGUAGES+= c c++
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/FreeImage

INSTALLATION_DIRS+= include lib

PLIST_SUBST+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}

NOT_FOR_PLATFORM=Darwin-*-*

.include "../../mk/bsd.pkg.mk"
