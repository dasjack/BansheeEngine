#pragma once

#include "CmPrerequisites.h"
#include "CmRenderTarget.h"

namespace CamelotEngine
{
	class CM_EXPORT MultiRenderTexture : public RenderTarget
	{
	public:
		virtual ~MultiRenderTexture();

		void setColorSurface(UINT32 surfaceIdx, TexturePtr texture, UINT32 face = 0, UINT32 numFaces = 1, UINT32 mipLevel = 0);
		void setDepthStencilSurface(TexturePtr depthStencil, UINT32 face = 0, UINT32 numFaces = 1, UINT32 mipLevel = 0);

		bool requiresTextureFlipping() const { return false; }

	protected:
		vector<TextureViewPtr>::type mColorSurfaces;
		TextureViewPtr mDepthStencilSurface;

		MultiRenderTexture();

		virtual void setColorSurfaceImpl(UINT32 surfaceIdx, TexturePtr texture, UINT32 face = 0, UINT32 numFaces = 1, UINT32 mipLevel = 0) = 0;
		virtual void setDepthStencilImpl(TexturePtr depthStencilstencil, UINT32 face = 0, UINT32 numFaces = 1, UINT32 mipLevel = 0) = 0;

		/**
		 * @copydoc RenderTarget::destroy_internal()
		 */
		virtual void destroy_internal();

	private:
		void throwIfBuffersDontMatch() const;

		virtual void copyContentsToMemory(const PixelData &dst, FrameBuffer buffer = FB_AUTO);
	};
}