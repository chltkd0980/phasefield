//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "phasefieldTestApp.h"
#include "phasefieldApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
phasefieldTestApp::validParams()
{
  InputParameters params = phasefieldApp::validParams();
  return params;
}

phasefieldTestApp::phasefieldTestApp(InputParameters parameters) : MooseApp(parameters)
{
  phasefieldTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

phasefieldTestApp::~phasefieldTestApp() {}

void
phasefieldTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  phasefieldApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"phasefieldTestApp"});
    Registry::registerActionsTo(af, {"phasefieldTestApp"});
  }
}

void
phasefieldTestApp::registerApps()
{
  registerApp(phasefieldApp);
  registerApp(phasefieldTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
phasefieldTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  phasefieldTestApp::registerAll(f, af, s);
}
extern "C" void
phasefieldTestApp__registerApps()
{
  phasefieldTestApp::registerApps();
}
