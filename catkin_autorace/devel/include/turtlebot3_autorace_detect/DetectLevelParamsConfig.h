//#line 2 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the turtlebot3_autorace_detect package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __turtlebot3_autorace_detect__DETECTLEVELPARAMSCONFIG_H__
#define __turtlebot3_autorace_detect__DETECTLEVELPARAMSCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace turtlebot3_autorace_detect
{
  class DetectLevelParamsConfigStatics;

  class DetectLevelParamsConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }

      virtual void clamp(DetectLevelParamsConfig &config, const DetectLevelParamsConfig &max, const DetectLevelParamsConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const DetectLevelParamsConfig &config1, const DetectLevelParamsConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, DetectLevelParamsConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const DetectLevelParamsConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, DetectLevelParamsConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const DetectLevelParamsConfig &config) const = 0;
      virtual void getValue(const DetectLevelParamsConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T DetectLevelParamsConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T DetectLevelParamsConfig::* field;

      virtual void clamp(DetectLevelParamsConfig &config, const DetectLevelParamsConfig &max, const DetectLevelParamsConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const DetectLevelParamsConfig &config1, const DetectLevelParamsConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, DetectLevelParamsConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const DetectLevelParamsConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, DetectLevelParamsConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const DetectLevelParamsConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const DetectLevelParamsConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, DetectLevelParamsConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, DetectLevelParamsConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T PT::* field;
      std::vector<DetectLevelParamsConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(DetectLevelParamsConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("hue_red_l"==(*_i)->name){hue_red_l = boost::any_cast<int>(val);}
        if("hue_red_h"==(*_i)->name){hue_red_h = boost::any_cast<int>(val);}
        if("saturation_red_l"==(*_i)->name){saturation_red_l = boost::any_cast<int>(val);}
        if("saturation_red_h"==(*_i)->name){saturation_red_h = boost::any_cast<int>(val);}
        if("lightness_red_l"==(*_i)->name){lightness_red_l = boost::any_cast<int>(val);}
        if("lightness_red_h"==(*_i)->name){lightness_red_h = boost::any_cast<int>(val);}
      }
    }

    int hue_red_l;
int hue_red_h;
int saturation_red_l;
int saturation_red_h;
int lightness_red_l;
int lightness_red_h;

    bool state;
    std::string name;

    
}groups;



//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int hue_red_l;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int hue_red_h;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int saturation_red_l;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int saturation_red_h;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int lightness_red_l;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int lightness_red_h;
//#line 228 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("DetectLevelParamsConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const DetectLevelParamsConfig &__max__ = __getMax__();
      const DetectLevelParamsConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const DetectLevelParamsConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const DetectLevelParamsConfig &__getDefault__();
    static const DetectLevelParamsConfig &__getMax__();
    static const DetectLevelParamsConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const DetectLevelParamsConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void DetectLevelParamsConfig::ParamDescription<std::string>::clamp(DetectLevelParamsConfig &config, const DetectLevelParamsConfig &max, const DetectLevelParamsConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class DetectLevelParamsConfigStatics
  {
    friend class DetectLevelParamsConfig;

    DetectLevelParamsConfigStatics()
    {
DetectLevelParamsConfig::GroupDescription<DetectLevelParamsConfig::DEFAULT, DetectLevelParamsConfig> Default("Default", "", 0, 0, true, &DetectLevelParamsConfig::groups);
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.hue_red_l = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.hue_red_l = 179;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.hue_red_l = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("hue_red_l", "int", 0, "hue_red_l", "", &DetectLevelParamsConfig::hue_red_l)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("hue_red_l", "int", 0, "hue_red_l", "", &DetectLevelParamsConfig::hue_red_l)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.hue_red_h = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.hue_red_h = 179;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.hue_red_h = 179;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("hue_red_h", "int", 0, "hue_red_h", "", &DetectLevelParamsConfig::hue_red_h)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("hue_red_h", "int", 0, "hue_red_h", "", &DetectLevelParamsConfig::hue_red_h)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.saturation_red_l = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.saturation_red_l = 255;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.saturation_red_l = 24;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("saturation_red_l", "int", 0, "saturation_red_l", "", &DetectLevelParamsConfig::saturation_red_l)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("saturation_red_l", "int", 0, "saturation_red_l", "", &DetectLevelParamsConfig::saturation_red_l)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.saturation_red_h = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.saturation_red_h = 255;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.saturation_red_h = 255;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("saturation_red_h", "int", 0, "saturation_red_h", "", &DetectLevelParamsConfig::saturation_red_h)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("saturation_red_h", "int", 0, "saturation_red_h", "", &DetectLevelParamsConfig::saturation_red_h)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.lightness_red_l = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.lightness_red_l = 255;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.lightness_red_l = 207;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("lightness_red_l", "int", 0, "lightness_red_l", "", &DetectLevelParamsConfig::lightness_red_l)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("lightness_red_l", "int", 0, "lightness_red_l", "", &DetectLevelParamsConfig::lightness_red_l)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.lightness_red_h = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.lightness_red_h = 255;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.lightness_red_h = 255;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("lightness_red_h", "int", 0, "lightness_red_h", "", &DetectLevelParamsConfig::lightness_red_h)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(DetectLevelParamsConfig::AbstractParamDescriptionConstPtr(new DetectLevelParamsConfig::ParamDescription<int>("lightness_red_h", "int", 0, "lightness_red_h", "", &DetectLevelParamsConfig::lightness_red_h)));
//#line 246 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(DetectLevelParamsConfig::AbstractGroupDescriptionConstPtr(new DetectLevelParamsConfig::GroupDescription<DetectLevelParamsConfig::DEFAULT, DetectLevelParamsConfig>(Default)));
//#line 366 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<DetectLevelParamsConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<DetectLevelParamsConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<DetectLevelParamsConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    DetectLevelParamsConfig __max__;
    DetectLevelParamsConfig __min__;
    DetectLevelParamsConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const DetectLevelParamsConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static DetectLevelParamsConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &DetectLevelParamsConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const DetectLevelParamsConfig &DetectLevelParamsConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const DetectLevelParamsConfig &DetectLevelParamsConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const DetectLevelParamsConfig &DetectLevelParamsConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<DetectLevelParamsConfig::AbstractParamDescriptionConstPtr> &DetectLevelParamsConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<DetectLevelParamsConfig::AbstractGroupDescriptionConstPtr> &DetectLevelParamsConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const DetectLevelParamsConfigStatics *DetectLevelParamsConfig::__get_statics__()
  {
    const static DetectLevelParamsConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = DetectLevelParamsConfigStatics::get_instance();

    return statics;
  }


}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __DETECTLEVELPARAMSRECONFIGURATOR_H__
