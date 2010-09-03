/*=========================================================================

   Program: ParaView
   Module:    PrismCubeAxesEditorDialog.h

   Copyright (c) 2005-2008 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2.

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

========================================================================*/
#ifndef __PrismCubeAxesEditorDialog_h
#define __PrismCubeAxesEditorDialog_h

#include <QDialog>
class vtkSMProxy;
class QDoubleSpinBox;

class  PrismCubeAxesEditorDialog : public QDialog
{
  Q_OBJECT
  typedef QDialog Superclass;
public:
  PrismCubeAxesEditorDialog(QWidget *parent=0, Qt::WindowFlags f=0);
  ~PrismCubeAxesEditorDialog();

  /// Set the representation proxy whose cube axes is controlled by this
  /// dialog.
  void setRepresentationProxy(vtkSMProxy* repr);

  /// Overridden to push changes if user hit accept.
  virtual void done(int r);

signals:
  /// Fired when the browser begins performing an undoable change.
  void beginUndo(const QString& label);

  /// Fired when the browser is finished with the undoable change.
  void endUndo();



private:
  PrismCubeAxesEditorDialog(const PrismCubeAxesEditorDialog&); // Not implemented.
  void operator=(const PrismCubeAxesEditorDialog&); // Not implemented.

  void setupCustomAxes( const double &min, const double &max,
    const bool &enabled, QDoubleSpinBox *minWidget, QDoubleSpinBox *maxWidget);

  class pqInternal;
  pqInternal* Internal;
};

#endif