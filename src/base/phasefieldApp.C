#include "phasefieldApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
phasefieldApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

phasefieldApp::phasefieldApp(InputParameters parameters) : MooseApp(parameters)
{
  phasefieldApp::registerAll(_factory, _action_factory, _syntax);
}

phasefieldApp::~phasefieldApp() {}

void
phasefieldApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"phasefieldApp"});
  Registry::registerActionsTo(af, {"phasefieldApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
phasefieldApp::registerApps()
{
  registerApp(phasefieldApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
phasefieldApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  phasefieldApp::registerAll(f, af, s);
}
extern "C" void
phasefieldApp__registerApps()
{
  phasefieldApp::registerApps();
}
