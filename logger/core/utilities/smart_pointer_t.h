/*
  Copyright 2021 Basavaraju B V

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef _SMART_POINTER_T_H_
#define _SMART_POINTER_T_H_

#include "stdint.h"

template <typename T>
class SmartPtr_t
{
  private:
    T* ptr;
    uint64_t* rc;
  
    void AssertionCheck(void* p)
    {
      if(p != nullptr)
      {
        return;
      }

      while(1)
      {
        // This is programmatic error
      }
    }

    void DecrementReference(void)
    {
      if(ptr == nullptr)
      {
        if(rc != nullptr)
        {
          delete rc;
          rc = nullptr;
        }

        return;
      }

      AssertionCheck(rc);

      if(*rc > 0)
      {
        *rc= *rc - 1;
      }

      if(*rc == 0)
      {
        delete ptr;
        delete rc;

        rc = nullptr;
        ptr = nullptr;
      }
    }

    void CheckMembersAndIncrementRc(void)
    {
      AssertionCheck(ptr);
      AssertionCheck(rc);

      *rc = *rc + 1;
    }

  public:
    SmartPtr_t()
    : ptr(nullptr)
    {
      rc = new uint64_t(0);
      AssertionCheck(rc);
    }

    SmartPtr_t(T* ptr_)
    : ptr(ptr_)
    {
      AssertionCheck(ptr);

      rc = new uint64_t(1);
      AssertionCheck(rc);
    }

    SmartPtr_t(T& obj)
    : ptr(&obj)
    {
      AssertionCheck(ptr);

      rc = new uint64_t(1);
      AssertionCheck(rc);
    }

    SmartPtr_t(const SmartPtr_t & obj)
    : ptr(obj.ptr),
      rc(obj.rc)
    {
      CheckMembersAndIncrementRc();
    }

    template<typename U>
    SmartPtr_t(const SmartPtr_t<U>& obj)
    : ptr(obj.GetRaw()),
      rc(obj.GetRc())
    {
      CheckMembersAndIncrementRc();
    }

    ~SmartPtr_t()
    {
      DecrementReference();
    }

    template<typename U>
    SmartPtr_t& operator=(const SmartPtr_t<U>& obj)
    {
      if((rc != nullptr) && (*rc > 0))
      {
        DecrementReference();
      }

      ptr = obj.ptr;
      rc = obj.rc;

      CheckMembersAndIncrementRc();
      return *this;
    }

    SmartPtr_t& operator=(const SmartPtr_t& obj)
    {
      if(this == &obj)
      {
        return *this;
      }

      if((rc != nullptr) && (*rc > 0))
      {
        DecrementReference();
      }

      ptr = obj.ptr;
      rc = obj.rc;

      CheckMembersAndIncrementRc();
      return *this;
    }

    SmartPtr_t& operator=(T* ptr_)
    {
      if((rc != nullptr) && (*rc > 0))
      {
        DecrementReference();
      }
      
      if(rc == nullptr)
      {
        rc = new uint64_t(0);
      }

      ptr = ptr_;

      CheckMembersAndIncrementRc();
      return *this;
    }

    T& operator*() const
    {
      return *ptr;
    }

    T* operator->() const
    {
      return ptr;
    }

    bool IsNull(void) const
    {
      return (ptr == nullptr);
    }

    T* GetRaw(void) const
    {
      return ptr;
    }

    //Note: It is meant for internal use only. It is recommended never to be used by any other class.
    //      It has been made public only to support SmartPtr_t(const SmartPtr_t<U>& obj)
    //      Soon after alternate approach has been identified, this function will be removed or made private.
    uint64_t* GetRc(void) const
    {
      return rc;
    }

    void Reset()
    {
      AssertionCheck(rc);
      if(*rc == 0)
      {
        ptr = nullptr;
        return;
      }

      DecrementReference();
      ptr = nullptr;
      rc = nullptr;
    }
};

#endif  //_SMART_POINTER_T_H_