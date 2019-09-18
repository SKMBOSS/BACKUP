#ifndef _MACRO_H_
#define _MACRO_H_
	
#define  DECLARE_SINGLETON(type)			\
public:										\
	static type** GetInstance()	{			\
		static type* pInstance = new type;  \
		if (pInstance == nullptr)			\
			pInstance = new type;			\
		return &pInstance;					\
	}										\
	static void DestroyInstance() {			\
		type** ppInstance = GetInstance();	\
		if (*ppInstance != nullptr) {		\
			delete *ppInstance;				\
			*ppInstance = nullptr;			\
		}									\
	}

#define COPY_PROTECTION(type)				\
private:									\
	type(const type& cpy);					\
	type& operator= (const type& cpy);		

#define GET_SINGLE(type) (*(type::GetInstance()))
#define DESTROY_SINGLE(type) type::DestroyInstance()

#define SAFE_DELETE(pointer)       if(pointer)  { delete   pointer; pointer = nullptr; }
#define SAFE_DELETE_ARRAY(pointer) if(pointer)  { delete[] pointer; pointer = nullptr; }

#define SAFE_RELEASE(pointer)	   if(pointer)  { pointer->Release(); SAFE_DELETE(pointer); }

#endif
