# $NetBSD: Makefile,v 1.19 2016/06/03 15:45:43 jperkin Exp $

DISTNAME=	alsa-lib-1.1.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	utils/alsa.pc.in

CONFIGURE_ARGS+=	--disable-python

CPPFLAGS.SunOS+=	-D__EXTENSIONS__ -DBSD_COMP -DMAP_FILE=0
CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600
CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t
CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t -Du_int64_t=uint64_t

CPPFLAGS.SunOS+=	-D__u32=uint32_t -D__u64=uint64_t
CPPFLAGS.NetBSD+=	-D__u32=uint32_t -D__u64=uint64_t
CPPFLAGS.FreeBSD+=	-D__u32=uint32_t -D__u64=uint64_t

LIBS.SunOS+=		-lsocket -lnsl

CONFIGURE_ARGS.SunOS+=		--without-versioned
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=Versions

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
