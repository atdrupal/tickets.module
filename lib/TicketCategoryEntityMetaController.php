<?php

class TicketCategoryEntityMetaController extends EntityDefaultMetadataController {
  public function entityPropertyInfo() {
    $info['properties'] = array(
      'uid'     => array('type' => 'user',  'label' => 'Author'),
      'created' => array('type' => 'date',    'label' => 'Created'),
      'changed' => array('type' => 'date',    'label' => 'Change'),
    );

    return array($this->type => $info);
  }
}